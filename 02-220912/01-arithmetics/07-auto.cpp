#include <iostream>

int main() {
    // Since C++11
    auto x = 1'000'000'000;   // int
    auto y = 1'000'000'000U;  // unsigned int
    auto x2 = 2 * x;          // int * int, int
    auto y2 = 2 * y;          // int * unsigned int, unsigned int
    std::cout << x2 << " " << y2 << " " << sizeof(x2) << "\n";

    // auto x3 = 2 * x, y3 = 2 * y;  // CE: inconsistent deduction for 'auto'

    auto z = 123'456'789'000;  // long long
    std::cout << z << " " << sizeof(z) << "\n";

    auto z2 = 0x123LL;
    std::cout << z2 << " " << sizeof(z2) << "\n";

    // `auto` works with other types as well, but it is always deduced from the
    // initialization.

    // Does not work:
    auto tmp; tmp = 12;
}
