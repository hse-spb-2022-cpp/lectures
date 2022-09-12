#include <iostream>

int main() {
    {
        std::cout << "===== long long =====\n";
        long long a = 9'000'000'000'000'000'000;
        std::cout << sizeof(a) << " " << sizeof(long long) << "\n";
        std::cout << a << "\n";
    }
    {
        std::cout << "===== conversions ===== \n";
        int x = 10;
        long long y = x;  // ok, implicit conversion
        y = y * 1'000'000'000;
        int z = y;  // ok, implicit conversion, possible loss of information,
                    // unspecified (not undefined!) behavior
        std::cout << x << " " << y << " " << z << "\n";
    }
    {
        std::cout << "===== unsigned long long =====\n";
        unsigned long long a =
            18'000'000'000'000'000'000U;  // need the 'U' suffix for big
                                          // unsigned decimal literals
        std::cout << a << "\n";
    }
    // All types and constraints:
    // https://en.cppreference.com/w/cpp/language/types
}
