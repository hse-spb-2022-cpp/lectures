# What is a library
The answer is heavily OS- and compiler- dependent.
Exact flags, naming conventions are not unified as well.

Typically everything comes from C, not C++.
Other languages have their own mechanisms (e.g. `import`s in Java/Python).

## Static library
A bunch of translation units embedded into your executable.
E.g. parts of Standard C++ Library.

E.g. `libsqlite3.a` (for msys2 and on Linux) or `sqlite3.lib` (for Visual Studio).

## Dynamic library, linked at compiled time
A bunch of translation units linked together with your executable.

E.g. `libstdc++-6.dll` for msys2 weigs 2MB and contains parts of C++ Standard Library.
It's necessary to run the executable.
It may have its own dependencies (e.g. C Standard Library or Microsoft C++ Runtime).

It may be possible to "link dynamic library statically", i.e. embed the library into the executable.

How to tell linker about the DLL is a separate issue.
Typically there is a helper static library like `libsqlite3.dll.a`.

## Dynamic library, loaded at run time
Very complex topic, see the "Linkers and Loaders" book by John R. Levine (not sure if outdated, I did not read it).
E.g. there are export/import tables, different sections, symbol visibility, weak symbols...
Not for us.

See example with `./main` and `./plugins/*.dll` (only a subset of plugins is available at any given moment).

# (skip?) Low-level
LoadLibrary, GetProcAddr, everything is C-style.

# Source code

# Compilation
## Manual with msys2
Ensure you have Boost installed.

Use `-shared` to compile DLL instead of EXE.

Add `-lboost_filesystem-mt` to link statically (aha!) with Boost.Filesystem.

## (skip?) Others
* It's better to add `-fPIC` (position-independent code), maybe something else from Boost.DLL's manual as well.
* Compile via CMakeLists (mingw, VS).

# (skip)? Gotchas
Separate heaps and standard libraries (`default_deleter` of `unique_ptr`), ABI incompatibilities...
Separate `std::cout` which may interleave with each other and main without proper synchronization.
