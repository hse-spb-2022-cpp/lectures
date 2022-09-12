#include <iostream>

int main() {
    std::cout << (3 & 5) << "\n";  // bitwise AND: 1
    std::cout << (3 | 5) << "\n";  // bitwise OR: 7
    std::cout << (3 ^ 5) << "\n";  // bitwise XOR: 6
    std::cout << ~3U << "\n";      // bitwise NOT: 2**32 - 3

    std::cout << "===== shifts =====\n";

    int a = 10;
    std::cout << (a << 3) << "\n";  // *2**3, *8
    std::cout << (a >> 2) << "\n";  // /2**2, /4

    std::cout << "===== shifts UB =====\n";
    a = -10;
    std::cout << (a >> 2) << "\n";  // Implementation-defined in C++17 and
                                    // prior, multiplication in C++20
    std::cout << (a << 3)
              << "\n";  // UB in C++17 and prior, multiplication in C++20

    std::cout << (a << 30) << "\n";  // UB: overflow
    std::cout << (a << 31) << "\n";  // UB: overflow

    int b = 32;
    std::cout << (a << b) << "\n";  // UB: shifting by 8*sizeof() bits
    std::cout << (a >> b) << "\n";  // UB: shifting by 8*sizeof() bits

    b = -1;
    std::cout << (a << b) << "\n";  // UB: shifting by negative
    std::cout << (a >> b) << "\n";  // UB: shifting by negative
}
