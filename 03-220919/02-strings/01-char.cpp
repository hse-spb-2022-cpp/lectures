#include <iostream>

int main() {
    std::cout << "char: " << sizeof(char)
              << "\n";  // Typically 1 byte, but is treated as "character" for
                        // I/O purposes. Still does arithmetics.
    [[maybe_unused]] int wtf = '0';
    char c = '0';  // Typically 48 (ASCII table; please do not use non-ASCII),
                   // note single quotes.
                   // https://en.cppreference.com/w/cpp/language/character_literal
    std::cout << c << " " << c - 1 /* char - int = int */ << " " << static_cast<char>(c - 1) << "\n";
    std::cout << static_cast<char>(48) << "\n";
    std::cout << '5' - '2' << "\n";  // promoted to `int`. `int - int`

    std::cout << '\'' << '\n';  // escaping of special characters: still a single int
    std::cout << "\"quotes\"\n";  // escaping works inside strings as well

    // Check: type `hello`, type `  h  e `
    std::cin >> c;  // Skips whitespaces, reads a single char
    std::cout << "char=" << c << " " << static_cast<int>(c) << "\n";
    std::cin >> c;  // Skips whitespaces, reads a single char
    std::cout << "char=" << c << " " << static_cast<int>(c) << "\n";
    // Alternative: std::cin.get(), will be later
}
