use core::fmt;

pub struct VersionInfo {
    pub version: &'static str
}

impl fmt::Display for VersionInfo {
    fn fmt(&self, formatter: &mut fmt::Formatter) -> fmt::Result {
        write!(formatter, "{}", self.version)?;
        Ok(())
    }
}

pub const fn version() -> VersionInfo {
    let version = match option_env!("PFCONFLS_RELEASE") {
        Some(version) => version,
        None => match option_env!("PFCONFLS_COMMIT_SHORT_HASH") {
            Some(hash) => hash,
            None => "unknown"
        }
    };
    VersionInfo { version }
}
