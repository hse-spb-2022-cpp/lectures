#include <cmath>
#include <iostream>

int main() {
    // Does not work for me locally.
    // Use <cmath> and std::abs or fabs.
    std::cout << abs(-23.5) << "\n";
    std::cout << fabs(-23.5) << "\n";
    std::cout << std::abs(-23.5) << "\n";

    std::cout << "rounding:\n";
    std::cout << static_cast<int>(-2.8) << " " << static_cast<int>(-2.2) << " " << static_cast<int>(2.2) << " " << static_cast<int>(2.8) << "\n";
    std::cout << std::floor(-2.8) << " " << std::floor(-2.2) << " " << std::floor(2.2) << " " << std::floor(2.8) << "\n";
    std::cout << std::ceil(-2.8) << " " << std::ceil(-2.2) << " " << std::ceil(2.2) << " " << std::ceil(2.8) << "\n";
    std::cout << std::round(-2.8) << " " << std::round(-2.2) << " " << std::round(2.2) << " " << std::round(2.8) << "\n";

    std::cout << ".5 is banking\n";
    std::cout << std::round(-2.5) << " " << std::round(2.5) << "\n";
    std::cout << std::round(-1.5) << " " << std::round(1.5) << "\n";
}
