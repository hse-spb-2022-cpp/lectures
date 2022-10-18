#include <cmath>
#include <iostream>

int main() {
    std::cout.precision(100);

    double x = 0.1;
    std::cout << x << "\n";
    std::cout << 10 * x << "\n";
    std::cout << (x + x + x + x + x) + (x + x + x + x + x) << "\n";
    std::cout << x + x + x + x + x + x + x + x + x + x << "\n";
    std::cout << "=====\n";

    std::cout << pow(10, 5) << "\n";
    std::cout << log(100'000) / log(10) << "\n";
    std::cout << log(1'000'000) / log(10) << "\n";
    std::cout << log(10'000'000) / log(10) << "\n";
    std::cout << log(100'000'000) / log(10) << "\n";
    std::cout << log(1'000'000'000) / log(10) << "\n";
    std::cout << log(1e10) / log(10) << "\n";
    std::cout << log(1e11) / log(10) << "\n";

    std::cout << "=====\n";
    std::cout << static_cast<int>(log(1'000'000'000) / log(10)) << "\n";
    std::cout << std::floor(log(1'000'000'000) / log(10)) << "\n";
    std::cout << std::ceil(log(1'000'000'000) / log(10)) << "\n";
    std::cout << std::round(log(1'000'000'000) / log(10)) << "\n";

    std::cout << "=====\n";
    std::cout << pow(sqrt(2), 2) << "\n";
    std::cout << pow(sqrt(3), 2) << "\n";
    std::cout << pow(sqrt(4), 2) << "\n";
    std::cout << pow(sqrt(5), 2) << "\n";
    std::cout << (pow(sqrt(5), 2) == 5) << "\n";

    // Compiler may convert between double/long double and shuffle operations.
    // Weird results may happen: https://codeforces.com/blog/entry/1059
}
