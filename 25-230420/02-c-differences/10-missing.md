# Alternatives
* `*_cast` --> C-style-cast `(float)1`.
* `int a{}` --> `int a = 0;`
* namespaces --> prepend library name to all functions
* references --> pointers
* `bool` --> `int` + `0`/`1` OR `<stdbool.h>`
* `using pint = int*` --> `typedef int *pint;`
* `new`/`delete` --> `malloc`/`free` bytewise
* move/copy constructor/assignment operator --> `memcpy`
* templates --> fptrs, `void*`, complicated macros

# Fully missing
* functions: overloading, default parameters
   * partially emulated: macro (`_Generic` and other magic)
* `std::vector`
* exceptions --> return code
