use core::fmt;
use std::any::Any;

use miette::Result;

use crate::thread::role::ThreadRole;

pub mod qos;
pub mod role;

pub struct JoinHandle<T = ()>(Option<std::thread::JoinHandle<T>>);

impl<T> JoinHandle<T> {
    pub fn join(mut self) -> Result<T, Box<(dyn Any + Send + 'static)>> {
        self.0.take().unwrap().join()
    }
}

impl<T> fmt::Debug for JoinHandle<T> {
    fn fmt(&self, formatter: &mut fmt::Formatter) -> fmt::Result {
        formatter.pad("JoinHandle {..}")
    }
}

impl<T> Drop for JoinHandle<T> {
    fn drop(&mut self) {
        let Some(inner) = self.0.take() else {
            return;
        };
        let result = inner.join();
        if std::thread::panicking() {
            return;
        }
        if result.is_ok() {
            return;
        }
        result.unwrap();
    }
}

impl<T> From<std::thread::JoinHandle<T>> for JoinHandle<T> {
    fn from(inner: std::thread::JoinHandle<T>) -> JoinHandle<T> {
        JoinHandle(Some(inner))
    }
}

pub struct Builder {
    role: ThreadRole,
    inner: std::thread::Builder
}

impl Builder {
    pub fn new(role: ThreadRole) -> Builder {
        Builder {
            role,
            inner: std::thread::Builder::new()
        }
    }

    pub fn name(self, name: String) -> Builder {
        Builder {
            inner: self.inner.name(name),
            ..self
        }
    }

    pub fn spawn<F, T>(self, f: F) -> std::io::Result<JoinHandle<T>>
    where
        F: FnOnce() -> T,
        F: Send + 'static,
        T: Send + 'static {
        self.inner
            .spawn(move || {
                if let Err(report) = self.role.apply_to_current_thread() {
                    tracing::warn!(
                        "Role could not be applied to current \
                         thread.\n\n{report}"
                    );
                }
                f()
            })
            .map(JoinHandle::from)
    }
}
