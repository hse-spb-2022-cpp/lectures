#include <cstddef>
#include <iostream>

int main() {
    std::cout << "short: " << sizeof(short) << "\n";  // Typically 2 bytes
    std::cout << "unsigned short: " << sizeof(unsigned short) << "\n";
    std::cout << "long: " << sizeof(long)
              << "\n";  // Typically 4 or 8 bytes (see msys2 vs Linux)
    std::cout << "std::size_t: " << sizeof(std::size_t)
              << "\n";  // Typically 4 or 8 bytes

    std::size_t x =
        -1;  // std::size_t is unsigned, used for sizes of arrays/variables...
    std::cout << x << "\n";
}
