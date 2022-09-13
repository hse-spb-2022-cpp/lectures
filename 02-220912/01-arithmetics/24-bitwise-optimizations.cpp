#include <iostream>

int main() {
    // Bit shifts and operations are very fast: https://www.nandgame.com/
    // https://godbolt.org/z/Y5hez7WMG
    int a;
    std::cin >> a;
    int b = a * 33;  // probably optimized to (a + (a << 5))
    std::cout << b << "\n";

    int c = a / 33;
    std::cout << c << "\n";

    int d = a / 32;
    std::cout << d << "\n";

    int e = a % 32;  // a is signed, so we have to handle `a < 0` and return
                     // a negative result
    std::cout << e << "\n";

    int f = a & 0b11111;  // always non-negative
    std::cout << f << "\n";

    int g = static_cast<unsigned>(a) % 32;  // can be optimized to &
    std::cout << g << "\n";
}
