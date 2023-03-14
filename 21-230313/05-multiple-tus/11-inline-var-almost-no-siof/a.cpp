#include <iostream>
#include <string>

inline int counter = 123;
inline constexpr int var2 = ++counter;
inline constexpr int var1 = ++counter;

void foo() {
    std::cout << "From foo()\n";
    std::cout << var1 << " " << &var1 << "\n";
    std::cout << var2 << " " << &var2 << "\n";
}
