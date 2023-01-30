#include <iostream>

#define FOO(a, b) st##a##b
#define NEW_VAR(id) int x##id

int main() {
    FOO(d::c, out) << "Hello World\n";
    NEW_VAR(123) = 10;
    std::cout << x123 << "\n";
}
