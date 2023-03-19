#include <iostream>

int main() {
    float x = 1.0;
    int y;

    static_assert(sizeof(x) == sizeof(y));
    // Аналог std::memcpy. Не UB.
    // Начиная с C++20 есть bit_cast<>.
    for (int i = 0; i < 4; i++) {
        reinterpret_cast<char*>(&y)[i] = reinterpret_cast<char*>(&x)[i];
    }

    std::cout << std::hex << y << "\n";
}
