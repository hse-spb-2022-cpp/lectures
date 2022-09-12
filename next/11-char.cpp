#include <iostream>

int main() {
    std::cout << "char: " << sizeof(char)
              << "\n";  // Typically 1 byte, but is treated as "character" for
                        // I/O purposes. Still does arithmetics.
    char c = '0';  // Typically 48 (ASCII table; please do not use non-ASCII),
                   // note single quotes.
    std::cout << c << " " << c - 1 << " " << static_cast<int>(c) << "\n";
    std::cout << static_cast<char>(48) << "\n";
    std::cout << '5' - '2' << "\n";  // promoted to `int`. `int - int`

    // Check: type `hello`, type `  h  e `
    std::cin >> c;  // Skips whitespaces, reads a single char
    std::cout << "char=" << c << " " << static_cast<int>(c) << "\n";
    std::cin >> c;  // Skips whitespaces, reads a single char
    std::cout << "char=" << c << " " << static_cast<int>(c) << "\n";
}

// TODO: signed, unsigned, non-latin, isspace...
