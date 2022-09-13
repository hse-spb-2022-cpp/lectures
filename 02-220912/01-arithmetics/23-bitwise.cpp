#include <iostream>

int main() {
    // 3 = 0b011
    // 5 = 0b101
    std::cout << (3 & 5) << "\n";  // bitwise AND: 1
    std::cout << (3 | 5) << "\n";  // bitwise OR: 7
    std::cout << (3 ^ 5) << "\n";  // bitwise XOR: 6
    std::cout << ~3U << "\n";      // bitwise NOT: 2**32 - 1 - 3

    std::cout << "===== shifts =====\n";
    int a = 10;
    std::cout << (a << 3) << "\n";  // *2**3, *8
    std::cout << (a >> 2) << "\n";  // /2**2, /4

    std::cout << "===== shifts overflow =====\n";
    std::cout << (a << 30) << "\n";  // UB: overflow
    std::cout << (a << 31) << "\n";  // UB: overflow

    unsigned a_u = 10;
    std::cout << (a_u << 30) << "\n";  // OK: unsigned overflow

    std::cout << "===== shifts UB =====\n";
    a = -10;

    // Implementation-defined in C++17 and prior, division in C++20
    // https://gcc.gnu.org/onlinedocs/gcc/Integers-implementation.html#Integers-implementation
    std::cout << (a >> 2) << "\n";

    // UB in C++17 and prior, multiplication in C++20
    std::cout << (a << 3) << "\n";

    int b = 32;
    std::cout << (0 << b) << "\n";  // UB: shifting by 8*sizeof() bits
    std::cout << (0 >> b) << "\n";  // UB: shifting by 8*sizeof() bits

    b = -1;
    std::cout << (0 << b) << "\n";  // UB: shifting by negative
    std::cout << (0 >> b) << "\n";  // UB: shifting by negative
}
