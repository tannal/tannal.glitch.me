# Get the Code, build, running, testing, logging and lsp


```bash

./configure

./configure -C --debug-node

time make -j20

real    14m31.301s
user    265m47.070s
sys     12m22.725s

ln -s ./out/Release/compile_commands.json .

```

node env context

isolate

## testing

cctest

## debugging

> The source code of Node.js itself is primarily written in C++ and JavaScript. The JS part is mostly under the lib directory and the C++ part is mostly under the src directory. There are also a bunch of third-party dependencies like v8 or libuv which are placed under the deps directory.

> The Node.js release binaries do not strip the debug symbols (surprised?) so you don’t necessarily have to build a debug build to get meaningful C/C++ stack traces or to do step debugging in a native debugger like LLDB or GDB.

## lsp

clangd

TSServer

[error] TSServer exited. Code: null. Signal: SIGTERM

# GPT-QA

## whatwg

node_http_parser.cc - This file implements the HTTP parser used by Node.js, which is responsible for parsing incoming HTTP requests and generating HTTP responses. Understanding this file helps you comprehend the HTTP protocol handling in Node.js.

node_http2.cc - This file contains the implementation of the HTTP/2 module in Node.js, which enables you to work with the HTTP/2 protocol. It is relevant for understanding and adding new features related to HTTP/2.

node_net.cc - This file implements the networking-related functionality in Node.js, including TCP and UDP socket handling. It is crucial for understanding and extending networking capabilities in Node.js.

node_url.cc - This file contains the implementation of the URL module in Node.js. Understanding this file helps you work with URLs, parsing, and formatting according to the WHATWG URL specification.

node_crypto.cc - This file contains the implementation of the Node.js crypto module, which provides cryptographic functionality. It may be relevant for adding new cryptographic features based on WHATWG specifications.

node_diagnostics.cc - This file implements the diagnostics-related functionality in Node.js, such as the console object and debugging capabilities. It can be useful for debugging and diagnosing issues related to web-based features.

node_repl.cc - This file contains the implementation of the Node.js REPL (Read-Eval-Print Loop), which allows you to interactively execute JavaScript code. Understanding this file can help you add new features to the REPL environment.

node_stream_base.h - This header file defines the base classes for working with streams in Node.js, including readable and writable streams. It is relevant for understanding and extending stream-related functionality.

node_worker.cc - This file implements the Worker module in Node.js, which allows you to run JavaScript code in separate threads. It can be useful for understanding and adding features related to web workers and multi-threading.

node_module_wrap.h and node_module_wrap.cc - These files define the mechanisms for creating and managing JavaScript modules in Node.js. Understanding these files helps you work with modules and potentially add new module-related features.

## testing

common.gypi and common.gypi.py: These files define the common build configurations and variables used in the Node.js project. Understanding these files is crucial for setting up the testing environment and build system.

test/: This directory contains various test files and folders that cover different aspects of Node.js. Exploring the tests in this directory will give you insights into how different features and modules are tested.

test/common/: This directory contains common test utilities and helper functions used across multiple test files. Understanding the utilities in this directory can help you develop reusable testing infrastructure and enhance testing capabilities.

test/parallel/: This directory contains tests that can run in parallel. The tests in this directory cover a wide range of functionalities and can provide insights into parallel testing strategies and best practices.

test/sequential/: This directory contains tests that must run sequentially due to dependencies or other constraints. Studying the tests in this directory will help you understand sequential testing scenarios and their implementation.

test/common.js: This file contains common setup and teardown logic for tests. Understanding this file will give you insights into how the testing environment is prepared and cleaned up for each test.

test/runner.js: This file is the test runner script that orchestrates the execution of tests. Understanding this file will help you understand the overall test execution flow and how different test files are integrated.

src/node_test_env.cc: This file defines the Node.js test environment, which provides a sandboxed runtime for running tests. Understanding this file is crucial for setting up the testing environment and executing tests securely.

src/inspector_agent.cc: This file contains the implementation of the Inspector Agent, which allows for debugging and profiling Node.js applications. Understanding this file can be helpful for adding debugging and profiling features to the testing infrastructure.

tools/test-npm/: This directory contains test files and utilities specifically related to testing the npm package manager in Node.js. Exploring these files can provide insights into how npm integration is tested and can guide you in adding new npm-related testing features.

## logging

src/node.h - This header file defines the core Node.js class and includes various important dependencies. Understanding this file will provide insights into the core structure and initialization of a Node.js application.

src/node.cc - This file contains the main entry point for a Node.js application. It initializes and starts the event loop, sets up various subsystems, and handles command-line arguments. Understanding this file will give you an overview of the application's execution flow and where logging can be integrated.

src/logging.cc - This file implements the logging infrastructure in Node.js. It defines functions and classes for logging messages at different levels, managing loggers, and configuring log output. Studying this file will give you a deep understanding of the existing logging mechanism in Node.js.

src/env-inl.h - This header file provides utility functions to retrieve environment variables. It can be relevant for configuring logging behavior based on environment variables or command-line arguments.

src/node_options.h - This header file defines the NodeOptions class, which represents the command-line options for a Node.js application. Understanding this class can help you add new logging-related command-line options.

src/util-inl.h - This header file provides various utility functions used throughout the Node.js source code. It might be useful for implementing helper functions or macros related to logging.

src/node_internals.h - This header file includes internal Node.js headers and provides access to internal APIs. Understanding this file can be helpful if you need to extend or modify the internal logging behavior of Node.js.

src/async_wrap-inl.h - This header file defines the internal AsyncWrap class, which is used for tracking asynchronous operations in Node.js. Understanding this class can provide insights into logging asynchronous operations or tracking their progress.

src/node_platform.h - This header file defines the NodePlatform class, which represents the underlying platform on which Node.js is running. It might be relevant for adding platform-specific logging features or integrations.

src/node_object_wrap.h - This header file defines the NodeObjectWrap class, which is used for wrapping C++ objects and exposing them to JavaScript in Node.js. Understanding this class can help you integrate logging into C++ objects that interact with JavaScript.

# module loading

src/node.h: This header file defines the core Node.js class and includes various important dependencies. Understanding this file will provide insights into the core structure and initialization of a Node.js application, including the module loading process.

src/node.cc: This file contains the main entry point for a Node.js application. It initializes and starts the event loop, sets up various subsystems, and handles command-line arguments. Understanding this file will give you an overview of the application's execution flow and where the module loading process can be modified or extended.

src/node_module.cc: This file implements the module loading functionality in Node.js. It handles resolving and loading modules based on the provided module identifier or file path. Studying this file will give you a deep understanding of the existing module loading mechanism in Node.js.

src/node_file.cc: This file provides functions for reading files and directories in Node.js. It might be relevant for understanding how Node.js locates and reads module files during the loading process.

src/env-inl.h: This header file provides utility functions to retrieve environment variables. It can be relevant for configuring module loading behavior based on environment variables or command-line arguments.

src/util-inl.h: This header file provides various utility functions used throughout the Node.js source code. It might be useful for implementing helper functions or macros related to module loading.

src/node_options.h: This header file defines the NodeOptions class, which represents the command-line options for a Node.js application. Understanding this class can help you add new module loading-related command-line options.

src/node_internals.h: This header file includes internal Node.js headers and provides access to internal APIs. Understanding this file can be helpful if you need to extend or modify the internal module loading behavior of Node.js.

src/bootstrap_node.h: This header file defines the BootstrapNode class, which represents the initial bootstrap module of a Node.js application. It might be relevant if you want to modify the initial module loading process or add custom initialization logic.

src/node_platform.h: This header file defines the NodePlatform class, which represents the underlying platform on which Node.js is running. It might be relevant for adding platform-specific module loading features or integratio

## ESM & CommonJS

src/node.h: This header file defines the core Node.js class and includes various important dependencies. Understanding this file will provide insights into the core structure and initialization of a Node.js application, including the module system implementation.

src/node.cc: This file contains the main entry point for a Node.js application. It initializes and starts the event loop, sets up various subsystems, and handles command-line arguments. Understanding this file will give you an overview of the application's execution flow and where the module system implementation can be modified or extended.

src/env-inl.h: This header file provides utility functions to retrieve environment variables. It can be relevant for configuring the module system behavior based on environment variables or command-line arguments.

src/node_options.h: This header file defines the NodeOptions class, which represents the command-line options for a Node.js application. Understanding this class can help you add new flags or options related to ESM/CommonJS features.

src/node_internals.h: This header file includes internal Node.js headers and provides access to internal APIs. Understanding this file can be helpful if you need to extend or modify the internal module system behavior of Node.js.

src/node_module.cc: This file implements the module loading functionality in Node.js. It handles resolving and loading modules based on the provided module identifier or file path. Studying this file will give you a deep understanding of the existing module loading mechanism in Node.js, which is relevant for both ESM and CommonJS modules.

src/module_wrap.cc: This file defines the ModuleWrap class, which represents a wrapped module object that can be used for executing module code. Understanding this class can be helpful if you need to modify the behavior of the module wrapper or add new features related to module execution.

src/inspector_agent.cc: This file implements the InspectorAgent class, which provides debugging and inspection capabilities for Node.js. Understanding this class can be relevant if you want to add ESM/CommonJS-specific debugging or inspection features.

src/bootstrap_node.h: This header file defines the BootstrapNode class, which represents the initial bootstrap module of a Node.js application. It might be relevant if you want to modify the initial module loading process or add custom logic for ESM/CommonJS interoperability.

src/node_platform.h: This header file defines the NodePlatform class, which represents the underlying platform on which Node.js is running. It might be relevant for adding platform-specific features or integrations related to ESM and CommonJS modules.

# community



# reference

https://joyeecheung.github.io/blog/2018/12/31/tips-and-tricks-node-core/