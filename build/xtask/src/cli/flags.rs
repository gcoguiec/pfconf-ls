xflags::xflags! {
    src "./src/cli/flags.rs"
    /// A set of custom cargo commands.
    cmd xtask {
        /// Use verbose output.
        repeated -v, --verbose
        /// Do not print log messages at all.
        optional -q, --quiet

        /// Remove all project build artifacts and their local dependencies.
        cmd mrproper {}

        /// Build configuration language server.
        cmd build-server {
            /// Compiles server for wasm32-wasi target.
            optional -w, --wasi
        }
        /// Remove artifacts generated by server build.
        cmd clean-server {}

        /// Generate parser and scanner from grammar definition.
        cmd generate-grammar {}
        /// Remove grammar project dependencies (i.e node_modules).
        cmd clean-grammar {}

        /// Build vscodium extension with its own embedded language server.
        cmd build-vscodium {}

        /// Commands related to the wasi-sdk.
        cmd wasi {
            /// Download and extract wasi-sdk to the vendor directory.
            cmd download-sdk {
                /// Keep downloaded release file even if its signature is invalid.
                optional -k, --keep
            }
            /// Attempt to update wasi-sdk present in the vendor directory.
            cmd update-sdk {
                /// Keep downloaded release file even if its signature is invalid.
                optional -k, --keep
            }
            /// Remove wasi-sdk directory and its tarball release (but not vendor directory).
            cmd clean-sdk {}
        }
    }
}

// generated start
// The following code is generated by `xflags` macro.
// Run `env UPDATE_XFLAGS=1 cargo build` to regenerate.
#[derive(Debug)]
pub struct Xtask {
    pub verbose: u32,
    pub quiet: bool,
    pub subcommand: XtaskCmd,
}

#[derive(Debug)]
pub enum XtaskCmd {
    Mrproper(Mrproper),
    BuildServer(BuildServer),
    CleanServer(CleanServer),
    GenerateGrammar(GenerateGrammar),
    CleanGrammar(CleanGrammar),
    BuildVscodium(BuildVscodium),
    Wasi(Wasi),
}

#[derive(Debug)]
pub struct Mrproper;

#[derive(Debug)]
pub struct BuildServer {
    pub wasi: bool,
}

#[derive(Debug)]
pub struct CleanServer;

#[derive(Debug)]
pub struct GenerateGrammar;

#[derive(Debug)]
pub struct CleanGrammar;

#[derive(Debug)]
pub struct BuildVscodium;

#[derive(Debug)]
pub struct Wasi {
    pub subcommand: WasiCmd,
}

#[derive(Debug)]
pub enum WasiCmd {
    DownloadSdk(DownloadSdk),
    UpdateSdk(UpdateSdk),
    CleanSdk(CleanSdk),
}

#[derive(Debug)]
pub struct DownloadSdk {
    pub keep: bool,
}

#[derive(Debug)]
pub struct UpdateSdk {
    pub keep: bool,
}

#[derive(Debug)]
pub struct CleanSdk;

impl Xtask {
    #[allow(dead_code)]
    pub fn from_env_or_exit() -> Self {
        Self::from_env_or_exit_()
    }

    #[allow(dead_code)]
    pub fn from_env() -> xflags::Result<Self> {
        Self::from_env_()
    }

    #[allow(dead_code)]
    pub fn from_vec(args: Vec<std::ffi::OsString>) -> xflags::Result<Self> {
        Self::from_vec_(args)
    }
}
// generated end
