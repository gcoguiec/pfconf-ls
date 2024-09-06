#![deny(unsafe_code)]
#![deny(unsafe_op_in_unsafe_fn)]

pub mod cli;
pub mod dispatch;
pub mod log;
pub mod lsp;
pub mod thread;
pub mod util;
pub mod version;
#[cfg(target_os = "wasi")]
pub mod wasi;
