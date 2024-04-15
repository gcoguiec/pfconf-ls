use crate::thread::qos::{
    current_thread_qos_class,
    set_current_thread_qos_class,
    HAS_THREAD_QOS
};

use miette::Result;

#[derive(Debug)]
pub enum ThreadRole {
    Worker,
    LatencySensitiveWorker
}

impl ThreadRole {
    pub(super) fn apply_to_current_thread(self) -> Result<()> {
        set_current_thread_qos_class(self.into())?;
        Ok(())
    }

    pub(super) fn assert_is_used_on_current_thread(self) {
        if !HAS_THREAD_QOS {
            return;
        }
        assert_eq!(current_thread_qos_class(), Some(self.into()));
    }
}
