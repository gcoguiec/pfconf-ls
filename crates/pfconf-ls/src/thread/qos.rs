use miette::Diagnostic;
use thiserror::Error;

use crate::thread::role::ThreadRole;

cfg_if::cfg_if! {
    if #[cfg(target_vendor = "apple")] {
        #[derive(Debug, Error, Diagnostic)]
        pub enum QoSError {
            #[error("Could not set a QoS class on a thread excluded from QoS system (errno={0})")]
            #[diagnostic(code(pfconf_ls::thread::qos::excluded_thread))]
            ExcludedThread(i32),

            #[error("Invalid QoS class value was passed to `pthread_set_qos_class_self_np`.")]
            #[diagnostic(
                code(pfconf_ls::thread::qos::invalid_qos_class),
                url("https://github.com/apple-oss-distributions/libpthread/blob/main/src/qos.c#L151")
            )]
            InvalidQoSClass
        }

        #[derive(Debug, Clone, Copy, PartialEq, Eq, PartialOrd, Ord)]
        pub(super) enum QoSClass {
            // From https://github.com/apple-oss-distributions/libpthread/blob/libpthread-519/include/sys/qos.h#L130
            //
            /// A QoS class value which indicates the absence or removal of QoS
            /// class information.
            ///
            /// As an API return value, may indicate that threads or pthread
            /// attributes were configured with legacy API incompatible or in conflict with
            /// the QoS class system.
            Unspecified,

            /// A QoS class which indicates work performed by this thread was not
            /// initiated by the user and that the user may be unaware of the results.
            ///
            /// Such work is requested to run at a priority below other work.
            /// The use of this QoS class indicates the work should be run in the most energy
            /// and thermally-efficient manner.
            Background,

            /// A QoS class which indicates work performed by this thread
            /// may or may not be initiated by the user and that the user is unlikely to be
            /// immediately waiting for the results.
            ///
            /// Such work is requested to run at a priority below critical user-
            /// interactive and user-initiated work, but relatively higher than low-level
            /// system maintenance tasks. The use of this QoS class indicates the work
            /// should be run in an energy and thermally-efficient manner. The progress of
            /// utility work may or may not be indicated to the user, but the effect of such
            /// work is user-visible.
            Utility,

            /// A default QoS class used by the system in cases where more specific
            /// QoS class information is not available.
            ///
            /// Such work is requested to run at a priority below critical user-
            /// interactive and user-initiated work, but relatively higher than utility and
            /// background tasks. Threads created by pthread_create() without an attribute
            /// specifying a QoS class will default to QoS_CLASS_DEFAULT. This QoS class
            /// value is not intended to be used as a work classification, it should only be
            /// set when propagating or restoring QoS class values provided by the system.
            Default,

            /// A QoS class which indicates work performed by this thread
            /// was initiated by the user and that the user is likely waiting for the
            /// results.
            ///
            /// Such work is requested to run at a priority below critical user-
            /// interactive work, but relatively higher than other work on the system. This
            /// is not an energy-efficient QoS class to use for large tasks. Its use
            /// should be limited to operations of short enough duration that the user is
            /// unlikely to switch tasks while waiting for the results. Typical
            /// user-initiated work will have progress indicated by the display of
            /// placeholder content or modal user interface.
            UserInitiated,

            /// A QoS class which indicates work performed by this thread is interactive with the user.
            ///
            /// Such work is requested to run at high priority relative to other
            /// work on the system. Specifying this QoS class is a request to run with
            /// nearly all available system CPU and I/O bandwidth even under contention.
            /// This is not an energy-efficient QoS class to use for large tasks. The use of
            /// this QoS class should be limited to critical interaction with the user such
            /// as handling events on the main event loop, view drawing, animation, etc.
            UserInteractive
        }

        pub(super) const HAS_THREAD_QOS: bool = true;

        pub(super) fn current_thread_qos_class() -> Option<QoSClass> {
            let mut raw_qos = libc::qos_class_t::QOS_CLASS_UNSPECIFIED;

            #[allow(unsafe_code)]
            if unsafe {
                libc::pthread_get_qos_class_np(libc::pthread_self(), &mut raw_qos, std::ptr::null_mut())
            } != 0 {
                return None
            }

            match raw_qos.into() {
                QoSClass::Unspecified => None,
                qos => Some(qos)
            }
        }

        pub(super) fn set_current_thread_qos_class(qos_class: QoSClass) -> Result<(), QoSError> {
            #[allow(unsafe_code)]
            if unsafe { libc::pthread_set_qos_class_self_np(qos_class.into(), 0) } == 0 {
                return Ok(());
            }

            #[allow(unsafe_code)]
            let errno = unsafe { *libc::__error() };
            match errno {
                libc::EPERM => Err(QoSError::ExcludedThread(errno)),
                libc::EINVAL => Err(QoSError::InvalidQoSClass),
                _ => unreachable!("`pthread_set_qos_class_self_np` returned an unexpected error {errno}")
            }
        }

        impl From<ThreadRole> for QoSClass {
            fn from(role: ThreadRole) -> Self {
                match role {
                    ThreadRole::LatencySensitiveWorker => QoSClass::Utility,
                    ThreadRole::Worker => QoSClass::UserInitiated
                }
            }
        }

        impl From<libc::qos_class_t> for QoSClass {
            fn from(raw_qos: libc::qos_class_t) -> Self {
                match raw_qos {
                    libc::qos_class_t::QOS_CLASS_USER_INTERACTIVE => QoSClass::UserInteractive,
                    libc::qos_class_t::QOS_CLASS_USER_INITIATED => QoSClass::UserInitiated,
                    libc::qos_class_t::QOS_CLASS_DEFAULT => QoSClass::Default,
                    libc::qos_class_t::QOS_CLASS_UTILITY => QoSClass::Utility,
                    libc::qos_class_t::QOS_CLASS_BACKGROUND => QoSClass::Background,
                    libc::qos_class_t::QOS_CLASS_UNSPECIFIED => QoSClass::Unspecified
                }
            }
        }

        #[allow(clippy::from_over_into)]
        impl Into<libc::qos_class_t> for QoSClass {
            fn into(self) -> libc::qos_class_t {
                match self {
                    QoSClass::UserInteractive => libc::qos_class_t::QOS_CLASS_USER_INTERACTIVE,
                    QoSClass::UserInitiated => libc::qos_class_t::QOS_CLASS_USER_INITIATED,
                    QoSClass::Default => libc::qos_class_t::QOS_CLASS_DEFAULT,
                    QoSClass::Utility => libc::qos_class_t::QOS_CLASS_UTILITY,
                    QoSClass::Background => libc::qos_class_t::QOS_CLASS_BACKGROUND,
                    QoSClass::Unspecified => libc::qos_class_t::QOS_CLASS_UNSPECIFIED
                }
            }
        }
    } else if #[cfg(target_os = "windows")] {
        #[derive(Debug, Error, Diagnostic)]
        pub enum QoSError {
            #[error("Could not set priority on current thread.")]
            #[diagnostic(code(pfconf_ls::thread::qos::setting_thread_priority_failed))]
            SettingThreadPriorityFailed
        }

        #[derive(Debug, Clone, Copy, PartialEq, Eq, PartialOrd, Ord)]
        pub(super) enum QoSClass {
            // From https://learn.microsoft.com/en-us/windows/win32/procthread/scheduling-priorities#priority-class
            //
            /// A QoS Class used by processes that monitor the system, such as screen savers
            /// or applications that periodically update a display.
            ///
            /// This prevents process threads that are not high priorities from interfering with higher-priority threads.
            Idle,

            /// A QoS Class designed for processor-intensive background threads to be sure thread can be preempted when necessary.
            Lowest,

            /// A QoS Class with the same focus as `QoSClass::Lowest` but with a slightly higher priority class.
            BelowNormal,

            /// All created threads use this default QoS class. It means the thread priority is the same as the process priority class.
            Normal,

            /// A QoS class designed for process's input thread to ensure the application's responsiveness to the user.
            AboveNormal,

            /// A QoS Class with the same focus as `QoSClass::AboveNormal` but with a slightly higher priority class.
            ///
            /// Use `Highest` with care. If a thread runs at the highest priority level for extended periods,
            /// other threads in the system will not get processor time.
            /// If several threads are set at high priority simultaneously, the threads lose their effectiveness.
            /// The high-priority class should be reserved for threads responding to time-critical events.
            Highest,

            /// A QoS Class that should almost never be used because this priority class interrupts
            /// system threads that manage mouse input, keyboard input, and background disk flushing.
            ///
            /// This class can be appropriate for applications that "talk" directly to hardware or that perform
            /// brief tasks that should have limited interruptions.
            TimeCritical
        }

        pub(super) const HAS_THREAD_QOS: bool = true;

        pub(super) fn current_thread_qos_class() -> Option<QoSClass> {
            use windows_sys::Win32::System::Threading::*;
            #[allow(unsafe_code)]
            let thread_priority = unsafe {
                GetThreadPriority(GetCurrentThread());
            }.into();
            Some(thread_priority.into())
         }

        pub(super) fn set_current_thread_qos_class(qos_class: QoSClass) -> Result<(), QoSError> {
            use windows_sys::Win32::System::Threading::*;
            #[allow(unsafe_code)]
            if unsafe {
                SetThreadPriority(GetCurrentThread(), qos_class.into())
            } == 0 {
                return Err(QoSError::SettingThreadPriorityFailed)
            }
            Ok(())
        }

        impl From<ThreadRole> for QoSClass {
            fn from(role: ThreadRole) -> Self {
                match role {
                    ThreadRole::LatencySensitiveWorker => QoSClass::AboveNormal,
                    ThreadRole::Worker => QoSClass::Normal
                }
            }
        }

        impl From<i32> for QoSClass {
            fn from(raw_priority: i32) -> Self {
                match raw_priority {
                    THREAD_PRIORITY_IDLE => QoSClass::Idle,
                    THREAD_PRIORITY_LOWEST => QoSClass::Lowest,
                    THREAD_PRIORITY_BELOW_NORMAL => QoSClass::BelowNormal,
                    THREAD_PRIORITY_NORMAL => QoSClass::Normal,
                    THREAD_PRIORITY_ABOVE_NORMAL => QoSClass::AboveNormal,
                    THREAD_PRIORITY_HIGHEST => QoSClass::Highest,
                    THREAD_PRIORITY_TIME_CRITICAL => QoSClass::TimeCritical,
                    _ => unreachable!("Cannot convert invalid '{raw_priority}' priority value to a QoSClass.")
                }
            }
        }

        #[allow(clippy::from_over_into)]
        impl Into<i32> for QoSClass {
            fn into(self) -> i32 {
                match self {
                    QoSClass::Idle => THREAD_PRIORITY_IDLE,
                    QoSClass::Lowest => THREAD_PRIORITY_LOWEST,
                    QoSClass::BelowNormal => THREAD_PRIORITY_BELOW_NORMAL,
                    QoSClass::Normal => THREAD_PRIORITY_NORMAL,
                    QoSClass::AboveNormal => THREAD_PRIORITY_ABOVE_NORMAL,
                    QoSClass::Highest => THREAD_PRIORITY_HIGHEST,
                    QoSClass::TimeCritical => THREAD_PRIORITY_TIME_CRITICAL
                }
            }
        }
    } else {
        #[derive(Debug, Error, Diagnostic)]
        pub enum QoSError {}

        #[derive(Debug, PartialEq)]
        pub(super) enum QoSClass {
            Default
        }

        impl From<ThreadRole> for QoSClass {
            fn from(_role: ThreadRole) -> Self {
                QoSClass::Default
            }
        }

        pub(super) const HAS_THREAD_QOS: bool = false;
        pub(super) fn current_thread_qos_class() -> Option<QoSClass> { None }
        pub(super) fn set_current_thread_qos_class(_qos_class: QoSClass) -> Result<(), QoSError> { Ok(()) }
    }
}
