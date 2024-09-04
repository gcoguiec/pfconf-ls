#![allow(unsafe_code)]
#![allow(unsafe_op_in_unsafe_fn)]

pub mod bindings;

use bindings::Guest;

struct Component;

impl Guest for Component {
    fn helloworld() -> String {
        String::from("Hello, World")
    }
}

bindings::export!(Component with_types_in bindings);
