#include <iostream>

int main() {
    std::cout << "short: " << sizeof(short) << "\n"; // Typically 2 bytes
    std::cout << "long: " << sizeof(long) << "\n"; // Typically 4 or 8 bytes
    std::cout << "long long: " << sizeof(long long) << "\n"; // Typically 8 bytes

    {
        long long a = 1'000'000'000'000'000'000;
        std::cout << a << "\n";
    }
    {
        int x = 10;
        long long y = x;  // ok, implicit conversion
        int z = y;  // ok, implicit conversion, possible loss of information
        std::cout << x << " " << y << " " << z << "\n";
    }
}
