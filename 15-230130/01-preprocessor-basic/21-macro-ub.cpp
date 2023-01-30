// #define private public  // UB
// #include <vector>

// #define true false // UB

// #define int long long  // UB

// Define of any keyword is UB

// https://github.com/menahishayan/rickroll.h  // Probably not UB, but macros are weird. Condolenses to IDEs.

#define __FOO__  // UB, double underscore
#define _Abotva  // UB, starts with underscore
