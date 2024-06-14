use std::process::Command;

fn main() {
    set_commit_info();
    #[cfg(feature = "zigbuild")]
    zigbuild(); // @TODO move all this to xtask?
}

fn set_commit_info() {
    let output = match Command::new("git")
        .arg("rev-parse")
        .arg("--short")
        .arg("HEAD")
        .output()
    {
        Ok(output) if output.status.success() => output,
        _ => return
    };
    let short_hash = String::from_utf8(output.stdout).unwrap();
    println!("cargo:rustc-env=PFCONFLS_COMMIT_SHORT_HASH={}", short_hash);
}

/// Builds project with `zig cc` instead of `gcc`.
// @TODO move all of that to xtask?
#[cfg(feature = "zigbuild")]
fn zigbuild() {}
