use std::{
    fmt::Debug,
    num::NonZeroUsize,
    sync::{Mutex, MutexGuard, PoisonError}
};

use lru::LruCache;
use miette::{Diagnostic, Result};
use once_cell::sync::Lazy;
use thiserror::Error;

static TOOLS_FLAG_CACHE_CAP: usize = 32;

pub type DependencyFlagCache = LruCache<&'static str, bool>;

#[derive(Debug, Error, Diagnostic)]
pub enum CacheError<Guard: Debug> {
    #[error("Cache mutex was poisoned, or the lock had already been acquired.")]
    #[diagnostic(code(xtask::cache::lock_error))]
    LockError(PoisonError<Guard>)
}

// @todo store tool path and version.
pub static TOOLS_FLAG_CACHE: Lazy<Mutex<DependencyFlagCache>> =
    Lazy::new(|| {
        Mutex::new(LruCache::new(
            NonZeroUsize::new(TOOLS_FLAG_CACHE_CAP)
                .expect("Invalid tools flag cache capacity")
        ))
    });

#[allow(dead_code)]
pub fn clear_dependency_flag_cache()
-> Result<(), CacheError<MutexGuard<'static, DependencyFlagCache>>> {
    match TOOLS_FLAG_CACHE.lock() {
        Ok(mut cache) => cache.clear(),
        Err(err) => return Err(CacheError::LockError(err))
    }
    Ok(())
}
