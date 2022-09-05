#include <iostream>

int main() {
    {
        std::cout << "===== int =====\n";
        int a = 10;
        std::cout << a << "\n";
        std::cout << sizeof(a) << " " << sizeof(int) << "\n";  // size in bytes, typically 4.
        a = -10;
        std::cout << a << "\n";  // negative numbers work

        a = 2'000'000'000;
        std::cout << a << "\n";  // 2e9 works
        a = a * 2;  // UB: signed overflow
        std::cout << a << "\n";  // 4e9 does not fit inside 4-byte `int` ([-2**31; 2**31-1]). My compiler wraps around.
    }
    {
        std::cout << "===== unsigned int =====\n";
        unsigned int a = 10;  // or just `unsigned`
        std::cout << a << "\n";
        std::cout << sizeof(a) << "\n";  // size in bytes, typically 4.
        a = -10;  // not UB: always modulo 2**32, i.e. 2**32 - 10
        std::cout << a << "\n";

        a = 4'000'000'000;
        std::cout << a << "\n";  // 4e9 works
        a = a * 2;  // not UB: modulo 2**32
        std::cout << a << "\n";
    }
    {
        std::cout << "===== long long =====\n";
        long long a = 9'000'000'000'000'000'000;
        std::cout << a << "\n";
    }
    {
        std::cout << "===== unsigned long long =====\n";
        long long a = 9'000'000'000'000'000'000;
        std::cout << a << "\n";
    }
}
