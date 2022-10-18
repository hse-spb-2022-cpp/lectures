#include <cmath>
#include <iostream>

int main() {
    // floating-point numbers
    double x = 1.2;
    x += 2.3;
    std::cout << x << "\n";

    std::cout.precision(100);
    std::cout << 0.1 + 0.2 << "\n";
    std::cout << 0.3 << "\n";
    std::cout << (0.1 + 0.2 == 0.3) << "\n";
    std::cout << (0.1 + 0.2 - 0.3) << "\n";
    std::cout << "=====\n";

    auto y = 1.2e100;  // double
    std::cout << y << "\n";
    std::cout << static_cast<float>(y) << "\n";

    double z = 1.23456789;
    std::cout << z << "\n";
    std::cout << static_cast<float>(z) << "\n";

    long double lz1 = 1.23456789;  // double literal
    long double lz2 = 1.23456789L;  // long double literal
    std::cout << lz1 << "\n";
    std::cout << lz2 << "\n";
    std::cout << static_cast<long double>(z) << "\n";
}
