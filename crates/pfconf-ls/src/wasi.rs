#![allow(unsafe_code)]
#![allow(unsafe_op_in_unsafe_fn)]

pub mod bindings;

use bindings::Guest;

struct Component;

impl Guest for Component {
    fn language_version() -> String {
        pfconf_tree_sitter::language().version().to_string()
    }
}

bindings::export!(Component with_types_in bindings);
