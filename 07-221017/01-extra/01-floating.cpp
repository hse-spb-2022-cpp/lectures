#include <cmath>
#include <iostream>

int main() {
    // floating-point numbers
    double x = 1.2;
    x += 2.3;
    std::cout << x << "\n";

    std::cout.precision(20);
    std::cout << 0.1 + 0.2 << "\n";
    std::cout << 0.3 << "\n";
    std::cout << (0.1 + 0.2 == 0.3) << "\n";
    std::cout << (0.1 + 0.2 - 0.3) << "\n";
    std::cout << "=====\n";

    std::cout << std::abs(-23.5) << "\n";  // TODO

    auto y = 1.2e100;  // double
    std::cout << y << "\n";
    std::cout << static_cast<float>(y) << "\n";

    double z = 1.23456789;
    std::cout.precision(20);
    std::cout << z << "\n";
    std::cout << static_cast<float>(z) << "\n";

    // Exists as well: long double
}
