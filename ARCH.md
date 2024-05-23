# Global Project Architecture

## Components

| Name               | Scope            | Location               | Description                                         |
| ------------------ | ---------------- | ---------------------- | --------------------------------------------------- |
| Language Server    | `ls` or `server` | `crates/`              | The language server itself.                         |
| Grammar            | `grammar`        | `grammar/`             | Provides scanner & parser for the language server.  |
| VSCodium Extension | `vscodium`       | `extensions/vscodium/` | Provides VSCodium a client for the language server. |
