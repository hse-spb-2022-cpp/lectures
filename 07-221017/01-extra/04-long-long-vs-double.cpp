#include <iostream>

int main() {
    long long x = 123'456'789'123'456'789;
    std::cout << x << "\n";
    std::cout << std::fixed << static_cast<double>(x) << "\n";

    double a = 1e100;
    double b = 1e100 + 1;
    std::cout << (a == b) << "\n";
    std::cout << (a == a + 1) << "\n";
}
