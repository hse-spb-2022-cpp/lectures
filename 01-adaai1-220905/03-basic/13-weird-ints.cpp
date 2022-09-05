#include <iostream>

int main() {
    std::cout << "bool: " << sizeof(bool) << "\n"; // Typically 1 byte, but can only hold false (0) and true (1)
    // https://notes.algoprog.ru/cpp/syntax.html#id10
    bool b = false;
    std::cout << b << "\n";
    b = true;
    std::cout << b << "\n";
    b = 55;  // not UB
    std::cout << b << "\n";

    std::cout << "char: " << sizeof(char) << "\n"; // Typically 1 byte, but is treated as "character" for I/O purposes (still does arithmetics)
    char c = '0';  // Typically 48 (ASCII table; please do not use non-ASCII)
    std::cout << c << " " << c - 1 << " " << static_cast<int>(c) << "\n";
}
