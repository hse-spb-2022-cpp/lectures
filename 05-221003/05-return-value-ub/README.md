API (Application Programming Interface)
    void foo();
    foo();

Gets converted by the compiler to:

ABI (Application Binary Interface)
    '_Z3foov' --> 
    (name mangling)

But return value type is not mangled.

Different compilers/flags => different ABIs => UB.
ABIs are incompatible and not checked.
    E.g.: size of `std::size_t`, `int*`, `int`, fields inside `std::vector`'s implementation...
    `long` vs `int`
