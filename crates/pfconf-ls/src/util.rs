use std::io::{stderr, IsTerminal};

pub fn is_terminal() -> bool {
    stderr().is_terminal()
}
