#include <iostream>

int main() {
    // https://godbolt.org/z/3j7Y8ndPr
    int a;
    std::cin >> a;
    int b = a * 33;  // probably optimized to (a + (a << 5)) even with -O0
    std::cout << b << "\n";

    int c = a / 33;  // probably optimized via multiplication
    std::cout << c << "\n";

    int d = a / 32;  // probably optimized via bitshifts
    std::cout << d << "\n";
}
