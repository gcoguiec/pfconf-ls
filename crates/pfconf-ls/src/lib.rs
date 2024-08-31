#![deny(unsafe_code)]
#![deny(unsafe_op_in_unsafe_fn)]

#[cfg(all(target_arch = "wasm32"))]
pub mod bindings;

pub mod cli;
pub mod dispatch;
pub mod log;
pub mod lsp;
pub mod thread;
pub mod util;
pub mod version;
