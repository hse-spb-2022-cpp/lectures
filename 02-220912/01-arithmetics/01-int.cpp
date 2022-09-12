#include <iostream>

int main() {
    int a = 10;
    std::cout << a << "\n";
    std::cout << sizeof(a) << " " << sizeof(int)
              << "\n";  // size in bytes, typically 4.
    a = -10;
    std::cout << a << "\n";  // negative numbers work

    a = 2'000'000'000;
    std::cout << a << "\n";  // 2e9 works

    a = a * 2;  // UB: signed overflow.
                // 4e9 does not fit inside 4-byte `int` ([-2**31; 2**31-1])
                // My compiler wraps around here, but it's not necessary.
    std::cout << a << "\n";
    if (a < 0) {  // TODO: NEVER DO THAT, SEE NEXT FILE
        std::cout
            << "Overflow detected. But it's actually UB already, no use.\n";
    }
}
