#include <iostream>

inline int counter = 123;  // Since C++17
// Behavior changes when commented out
inline constexpr int var1 = ++counter;
inline constexpr int var2 = ++counter;

struct Foo {
    static inline int value = 10;
};

void foo();

int main() {
    std::cout << "From main()\n";
    std::cout << var1 << " " << &var1 << "\n";
    std::cout << var2 << " " << &var2 << "\n";
    std::cout << Foo::value << " " << &Foo::value << "\n";
    foo();
}
