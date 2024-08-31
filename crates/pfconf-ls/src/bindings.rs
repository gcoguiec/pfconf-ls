#![allow(unsafe_code)]
#![allow(unsafe_op_in_unsafe_fn)]

wit_bindgen::generate!({
    world: "pfconf-ls"
});

struct Component;

impl Guest for Component {
    fn helloworld() -> String {
        String::from("Hello, World")
    }
}

export!(Component);
