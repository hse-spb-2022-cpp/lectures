#include <iostream>

int main() {
    unsigned int a = 10;  // or just `unsigned`
    std::cout << a << "\n";
    std::cout << sizeof(a) << " " << sizeof(int)
              << "\n";  // size in bytes, typically 4.
    a = -10;  // not UB: always modulo 2**32 (depending on size), i.e. 2**32 -
              // 10
    std::cout << a << "\n";

    a = 4'000'000'000;
    std::cout << a << "\n";  // 4e9 works
    a = a * 2;               // not UB: modulo 2**32
    std::cout << a << "\n";
    if (a < 0) {  // always false
        std::cout << "Always non-negative number is negative??\n";
    }

    // Not ok: `unsigned > signed` is `unsigned > unsigned`, `-1` is
    // taken modulo 2**32. See "Usual arithmetic conversions" in
    // https://en.cppreference.com/w/c/language/conversion
    if (a > -1) {
        std::cout << "OK\n";
    } else {
        std::cout << "Always non-negative number is not greater than -1??\n";
    }
}
