#include <iostream>

int main() {
    std::cout << 7 / 3 << " " << 7 % 3 << "\n";  // 2 1, int / int is int

    // -2 -1 or -3 2, was implementation-defined behavior (sic!):
    // https://stackoverflow.com/questions/2397984/undefined-unspecified-and-implementation-defined-behavior
    // Since N2757 https://cplusplus.github.io/CWG/issues/614.html it is always
    // -2 -1
    std::cout << -7 / 3 << " " << -7 % 3 << "\n";

    // -2 1 since N2757
    std::cout << 7 / -3 << " " << 7 % -3 << "\n";

    // 2 -1 since N2757
    std::cout << -7 / -3 << " " << -7 % -3 << "\n";

    int x = 0;
    std::cout << 1 / x << "\n";  // UB
    std::cout << "OK 1\n";
    std::cout << 1 % x << "\n";  // UB
    std::cout << "OK 2\n";
}
