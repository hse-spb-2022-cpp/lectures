#include <cmath>
#include <iostream>

int main() {
    int k = 5;

    std::cout.precision(100);
    std::cout << pow(10, k) << "\n";
    int result = 1;
    for (int i = 0; i < k; i++) {
        result *= 10;
    }

    std::cout << log(100'000) / log(10) << "\n";
    std::cout << log(1'000'000) / log(10) << "\n";
    std::cout << log(10'000'000) / log(10) << "\n";
    std::cout << log(100'000'000) / log(10) << "\n";
    std::cout << log(1'000'000'000) / log(10) << "\n";

    std::cout << static_cast<int>(log(1'000'000'000) / log(10)) << "\n";  // down, to 0
    std::cout << std::floor(log(1'000'000'000) / log(10)) << "\n";  // down, to -inf
    std::cout << std::ceil(log(1'000'000'000) / log(10)) << "\n";  // up, to +inf
    std::cout << std::round(log(1'000'000'000) / log(10)) << "\n";  // nearest

    std::cout << "=====\n";
    std::cout << pow(sqrt(2), 2) << "\n";
    std::cout << pow(sqrt(3), 2) << "\n";
    std::cout << pow(sqrt(4), 2) << "\n";
    std::cout << pow(sqrt(5), 2) << "\n";
    std::cout << (pow(sqrt(5), 2) == 5) << "\n";
}
// TODO: https://codeforces.com/blog/entry/1059?locale=ru
