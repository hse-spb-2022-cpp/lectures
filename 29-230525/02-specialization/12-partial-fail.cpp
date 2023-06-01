#include <iostream>
#include <type_traits>

template<int I>
struct foo {
};

template<int I>
struct foo<2 * I> {  // Compilation error: cannot solve "real" equations
    static inline const bool value = I;
};

int main() {
    std::cout << foo<10>::value << "\n";
}
