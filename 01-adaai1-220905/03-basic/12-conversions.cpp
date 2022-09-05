#include <iostream>

int main() {
    int a = 1'000'000'000;
    {
        long long b = a * a;  // UB: int * int is calculated inside int (signed overflow, UB), and is then converted to long long
        // Check with -fsanitize=undefined
        // See " Usual arithmetic conversions" in https://en.cppreference.com/w/c/language/conversion
        std::cout << b << "\n";
    }
    {
        long long b = static_cast<long long>(a) * a;  // long long * int
        std::cout << b << "\n";
    }
    {
        // Olympiadic style.
        long long b = 1LL * a * a;  // long long * int * int
        std::cout << b << "\n";
    }
    {
        // C-style cast, do not use.
        long long b = (long long)a * a;  // long long * int
        std::cout << b << "\n";
    }
}
