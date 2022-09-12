#include <iostream>

// https://en.cppreference.com/w/cpp/language/integer_literal

int main() {
    int a;

    std::cout << 1'2345 << "\n";  // C++14

    a = 123;                                                    // decimal
    std::cout << a << " " << 100 * 1 + 10 * 2 + 1 * 3 << "\n";  // 123

    a = 0x2F;                                          // hexadecimal
    std::cout << a << " " << 2 * 16 + 1 * 15 << "\n";  // 47

    a = 0123;                                                 // octal
    std::cout << a << " " << 64 * 1 + 8 * 2 + 1 * 3 << "\n";  // 83

    a = 0b1101;                                  // binary (C++14)
    std::cout << a << " " << 8 + 4 + 1 << "\n";  // 13
}
