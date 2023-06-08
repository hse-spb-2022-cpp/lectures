#include <iostream>

// Order:
// 1. Name resolution. Output: "overload set".
// NEW a) Also: ADL (argument-dependent lookup)
// NEW b) Also: template argument deduction (unless removed via SFINAE)
// 2. Overload resolution. Output: a single overload.
// NEW a) Choosing "viable" functions: can theoretically be called (number of arguments match, there are conversions)
// NEW b) Choosing "best viable" function
// NEW Extra out-of-scope details at https://en.cppreference.com/w/cpp/language/overload_resolution
// 3. Access check.
// 4. Call, can be virtual or non-virtual.

void foo(const int&) {
    std::cout << "1\n";
}

void foo(char) {
    std::cout << "2\n";
}

template<typename T>
void foo(T) {
    std::cout << "3\n";
}

template<typename T>
void foo(T&) {
    std::cout << "4\n";
}

int main() {
    foo(10);  // Arg=int. Overload set: 1, 2, 3 (T=int), 4 (T=int)
              // Viable: 1, 2, 3 (T=int)
              // Best viable: 1 (similar conversion with 3, but templates are worse)
    foo('1');  // Arg=char. Overload set: 1, 2, 3 (T=char), 4 (T=char)
               // Viable: 1, 2, 3 (T=char)
               // Best viable: 2 (similar conversion with 3, but templates are worse)
    foo(10.0);  // Arg=double. Overload set: 1, 2, 3 (T=double), 4 (T=double)
                // Viable: 1, 2, 3 (T=double)
                // Best viable: 3 (better argument match: no floating-integral conversions)
}
