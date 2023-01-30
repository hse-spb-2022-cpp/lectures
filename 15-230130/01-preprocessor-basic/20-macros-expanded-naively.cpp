#include <iostream>

#define THREE 1 + 2
#define ZERO 1 - 1

int main() {
    std::cout << THREE * 3 << "\n";
    // However, `#if` computes integers
    #if THREE == 3
    std::cout << "Three indeed\n";
    #else
    std::cout << "Not three\n";
    #endif

    #if ZERO
    std::cout << "Zero is the truth\n";
    #else
    std::cout << "Zero is the lie\n";
    #endif
}
