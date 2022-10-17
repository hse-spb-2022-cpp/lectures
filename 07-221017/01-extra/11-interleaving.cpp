#include <iostream>

bool a = false, b = false;

int f(bool) {
    std::cout << "f(" << a << b << ")\n";
    return true;
}

int main() {
    // GCC: f(10), f(11)
    // MSVC: f(11), f(11)
    std::cout << f(a = true) + f(b = true) << "\n";
}
