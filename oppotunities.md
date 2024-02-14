
# startup

https://www.fermyon.com/

https://github.com/envoyproxy/envoy

Tetrate

Fastly

# Linux Foundation Mentorship

https://mentorship.lfx.linuxfoundation.org/#my-tasks


# Support clang plugins on windows LLVM

Description of the project: The Clang compiler is part of the LLVM compiler infrastructure and supports various languages such as C, C++, ObjC and ObjC++. The design of LLVM and Clang allows the compiler to be extended with plugins[1]. A plugin makes it possible to run extra user defined actions during a compilation. Plugins are supported on unix and darwin but not on windows due to some specifics on the windows platform.

The general work that needs to be done is to annotate all the public API surface with __declspec(dllexport) and similar if they are being built as a dynamically linked library (and nothing if being built statically). When the library is being consumed the attribute on the same declaration must be __declspec(dllimport) or the same spelling for the GNU version for ELF and MachO. Note that the attribute changes between the implementation and consumer and between static and dynamic linking. This is normally controlled by expansion to a macro.

Expected result: This project aims to allow make clang -fplugin=windows/plugin.dll work. The implementation approach should extend the working prototype [3] and extend the annotation tool [4]. The successful candidate should be prepared to attend a weekly meeting, make presentations and prepare blog posts upon request.

Further reading [1] https://clang.llvm.org/docs/ClangPlugins.html

[2] https://discourse.llvm.org/t/clang-plugins-on-windows

[3] https://github.com/llvm/llvm-project/pull/67502

[4] https://github.com/compnerd/ids

Project size:Either medium or large.

Difficulty: Medium

Confirmed Mentor: Vassil Vassilev, Saleem Abdulrasool 3