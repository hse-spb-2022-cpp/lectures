Libraries consist of two parts:

1. **Headers**. Source code in C++ and C.
   Function declarations and some other stuff.
   Some functions _can be_ defined in headers, we just don't know the syntax (it's easy, though).
2. **Binaries** (optional). Compiled source code, to be linked with your program.

Header-only libraries: e.g. `doctest`. Are very easy to use.

Binaries are different for different compilers and settings, require *ABI compatibility*.

Types of binaries:

* Static library. `lib****.a` with GCC/Clang or `****.lib` with MSVC.
  An archive of multiple `.o` files, just a separate translation unit.

* Dynamic library. `*.dll` on Windows, `lib*.so` on Linux, `*.dylib` on macOS.
  A separate executable with its own global variables, heap and dependencies.
  Can be (un)loaded on demand.
  * Can be loaded on start, e.g. `libstdc++.dll` in msys2.
    There is a corresponding static library.
  * Can be loaded on demand. Examples: editor plugins, game mods.
    In Java/Python it's free.

https://github.com/fffaraz/awesome-cpp

How to configure:

1. Set up include path. Either works or `-I/some/path` for GCC.
2. Set up library binaries path. Either works or `-L/some/path` for GCC.
3. Tell linker which libraries to use: `-lfoo` means `libfoo.a` or `foo.lib` depending on the compiler ("decorated")
4. (optional) Put dynamic libraries next to the app or add them to the `PATH` so it can be found on startup.
