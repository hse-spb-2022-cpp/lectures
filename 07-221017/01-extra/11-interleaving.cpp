#include <iostream>

bool a = false, b = false;

int f(bool, int x) {
    std::cout << "f(" << a << b << ", " << x << ")\n";
    return true;
}

int main() {
    // GCC: f(10, 1), f(11, 2)
    // MSVC: f(11, 2), f(11, 1)
    std::cout << f(a = true, 1) + f(b = true, 2) << "\n";
}
