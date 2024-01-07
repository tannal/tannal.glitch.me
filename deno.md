# rust toolchain

```bash

rustup show

rustup update

rustup default

rustup default stable
rustup default nightly

rm -rf ~/.rustup/toolchains/1.75.0-x86_64-unknown-linux-gnu/

```
# directory structure

tools/ deno subcommand ex tools/info.rs -> deno info

# build run testing logging

```bash

git clone https://github.com/denoland/deno

cd ~/tannalwork/projects/deno

git submodule update --init .


sudo apt install protobuf-compiler

cargo test

cargo test file_fetcher::tests::test_fetch_gzip

cargo test tsc::tests::test_emit_tsbuildinfo

cargo test --package deno --test integration_tests -- integration::repl::console_log --exact --nocapture

cargo test module::module::

#[test]d

#[cfg(test)]
mod tests {}



```

# layout 2020


box tree
                -> stacking context tree -> WebRender display list
fragment tree

For example, when a text sequence is broken into multiple lines or a block is broken across columns or pages, it yields multiple fragments in the tree.

```rust



pub struct DisplayList {
    pub list: Vec<DisplayItem>,
    pub clip_scroll_nodes: Vec<ClipScrollNode>,
}


```

# debug in vscode


```json

{
    // Launch configuration for debugging Rust code inside VS Code with LLDB
    // This configuration is used by the extension 'LLDB Debugger'
    // 
    // The necessary extension may be downloaded at: https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb
    // Alternatively, the repository for it may be found at: https://github.com/vadimcn/vscode-lldb.git
    
    "version": "0.1.0",
    "configurations": [
        {
            "name": "Debug with LLDB",
            "type": "lldb",
            "request": "launch",
            // The following configuration option, 'program', may in some cases need to be modified. 
            // This is so that the correct executable is targeted.
            // For example, on non-Windows systems, the ".exe" suffix must be removed. 
            // Alternatively, the directory that rustc/cargo outputs debug builds may change in future
            // As such, this path would have to change accordingly.
            "program": "${workspaceFolder}/target/debug/${workspaceFolderBasename}.exe",
            // If you wish to supply arguments/parameters to the program, supply them below:
            "args": [],
            // Working folder for execution. Change as necessary if program requires a different value:
            "cwd": "${workspaceFolder}",
            "terminal": "external",
            "stopOnEntry": false,
            // Instructs LLVM to apply special Rust-language-specific functionality to its analysis:
            "sourceLanguages": ["rust"]
        }
    ]
}

```