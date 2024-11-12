
- https://github.com/gfx-rs
- https://github.com/rust-cross/


# The compiler contribution book

// 生成阶段
- MIR 优化
- 常量求值
- 单态化
- MIR 降级
- 代码生成
- LLVM 集成

# 所有权系统

# 生命周期系统

# 对象模型

# 线程/并发模型

# 类型系统和泛型

# FFI

# 宏系统

# 异步运行时

# projects

rust-analyzer

cargo

clippy

rust-analyzer

https://github.com/rust-windowing

https://github.com/rust-cross/

https://github.com/rust-embedded/

https://github.com/rust-unofficial/

https://github.com/rust-osdev/

https://github.com/rust-skia

https://github.com/Rust-GCC

https://github.com/rust-mobile/

https://github.com/gfx-rs/


# people

involves:LegionMammal978
involves:a1phyr
involves:Urhengulas
involves:scottmcm
involves:bjorn3
involves:clarfonthey
involves:CraftSpider
involves:deltragon
involves:slanterns
involves:madsmtm
involves:teor2345
involves:PoignardAzur
involves:joshtriplett
involves:Nadrieril
involves:programmerjake
involves:nbdd0121
involves:Veykril
involves:obi1kenobi
involves:davidhewitt
involves:Manishearth
involves:Darksonn
involves:kpreid
involves:RalfJung
involves:tmandry


involves:Amanieu
involves:BurntSushi
involves:dtolnay
involves:joshtriplett
involves:m-ou-se

involves:yoshuawuyts
involves:compiler-errors
involves:Mark-Simulacrum
involves:carols10cents
involves:nikomatsakis
involves:ashleygwilliams
involves:nrc
involves:tbu-
involves:cuviper
involves:RReverser

# inbox

./x dist --target mips64-openwrt-linux-musl --host x86_64-unknown-linux-gnu

https://github.com/rust-lang/rustup/issues/904

https://internals.rust-lang.org/t/globalalloc-alloc-for-zero-sized-layouts/21791/7

```bash

git clone https://github.com/rust-lang/rust

bootstrap

./x

build/x86_64-unknown-linux-gnu/
├── ci-llvm
│   ├── bin
│   ├── include
│   └── lib
├── rustfmt
│   ├── bin
│   ├── lib
│   ├── libexec
│   └── share
├── stage0
│   ├── bin
│   ├── etc
│   ├── lib
│   ├── libexec
│   └── share
├── stage0-rustc
│   ├── release
│   └── x86_64-unknown-linux-gnu
├── stage0-std
│   ├── release
│   └── x86_64-unknown-linux-gnu
├── stage0-sysroot
│   ├── bin
│   └── lib
├── stage0-tools
│   ├── release
│   └── x86_64-unknown-linux-gnu
├── stage1
│   ├── bin
│   └── lib
└── stage1-std
    ├── release
    └── x86_64-unknown-linux-gnu


```


# tips

? is like if (err!=nil) {return err} in go


# tokio

tokio task

deno use tokio task spawn to run subcommand

# community


https://rust-lang.zulipchat.com/#all_messages


# appendix

Usage: x.py <subcommand> [options] [<paths>...]

Commands:
  build    Compile either the compiler or libraries
  check    Compile either the compiler or libraries, using cargo check
  clippy   Run Clippy (uses rustup/cargo-installed clippy binary)
  fix      Run cargo fix
  fmt      Run rustfmt
  doc      Build documentation
  test     Build and run some test suites
  bench    Build and run some benchmarks
  clean    Clean out build directories
  dist     Build distribution artifacts
  install  Install distribution artifacts
  run      Run tools contained in this repository
  setup    Set up the environment for development
  suggest  Suggest a subset of tests to run, based on modified files

Arguments:
  [PATHS]...  paths for the subcommand
  [ARGS]...   arguments passed to subcommands

Options:
  -v, --verbose...
          use verbose output (-vv for very verbose)
  -i, --incremental
          use incremental compilation
      --config <FILE>
          TOML configuration file for build
      --build-dir <DIR>
          Build directory, overrides `build.build-dir` in `config.toml`
      --build <BUILD>
          build target of the stage0 compiler
      --host <HOST>
          host targets to build
      --target <TARGET>
          target targets to build
      --exclude <PATH>
          build paths to exclude
      --skip <PATH>
          build paths to skip
      --include-default-paths
          include default paths in addition to the provided ones
      --rustc-error-format <RUSTC_ERROR_FORMAT>

      --on-fail <CMD>
          command to run on failure
      --dry-run
          dry run; don't build anything
      --dump-bootstrap-shims
          Indicates whether to dump the work done from bootstrap shims
      --stage <N>
          stage to build (indicates compiler to use/test, e.g., stage 0 uses the bootstrap compiler, stage 1 the stage 0 rustc artifacts, etc.)
      --keep-stage <N>
          stage(s) to keep without recompiling (pass multiple times to keep e.g., both stages 0 and 1)
      --keep-stage-std <N>
          stage(s) of the standard library to keep without recompiling (pass multiple times to keep e.g., both stages 0 and 1)
      --src <DIR>
          path to the root of the rust checkout
  -j, --jobs <JOBS>
          number of jobs to run in parallel [default: 24]
      --warnings <deny|warn>
          if value is deny, will deny warnings if value is warn, will emit warnings otherwise, use the default configured behaviour [default: default] [possible values: deny, warn, default]
      --error-format <FORMAT>
          rustc error format
      --json-output
          use message-format=json
      --color <STYLE>
          whether to use color in cargo and rustc output [default: auto] [possible values: always, never, auto]
      --bypass-bootstrap-lock
          Bootstrap uses this value to decide whether it should bypass locking the build process. This is rarely needed (e.g., compiling the std library for different targets in parallel)
      --llvm-skip-rebuild <VALUE>
          whether rebuilding llvm should be skipped, overriding `skip-rebuld` in config.toml [possible values: true, false]
      --rust-profile-generate <PROFILE>
          generate PGO profile with rustc build
      --rust-profile-use <PROFILE>
          use PGO profile for rustc build
      --llvm-profile-use <PROFILE>
          use PGO profile for LLVM build
      --llvm-profile-generate
          generate PGO profile with llvm built for rustc
      --enable-bolt-settings
          Enable BOLT link flags
      --skip-stage0-validation
          Skip stage0 compiler validation
      --reproducible-artifact <REPRODUCIBLE_ARTIFACT>
          Additional reproducible artifacts that should be added to the reproducible artifacts archive
      --set <section.option=value>
          override options in config.toml
  -h, --help
          Print help (see more with '--help')
