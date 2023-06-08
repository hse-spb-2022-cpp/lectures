#include <iostream>

auto foo();
auto bar();

auto foo() {
    return 10;
}

int main() {
    std::cout << foo() << "\n";
    // std::cout << bar() << "\n";  // compilation error: `auto` is not deduced, it's in another TU.
}
