#include <iostream>

int main() {
    // comma operators evaluates left, then right, returns right:
    // https://en.cppreference.com/w/cpp/language/operator_other used to show
    // off:
    int a = 0, b = 0, c = 0;
    std::cout << (a = 1, b = 2, c = 3) << "\n";  // 3
    std::cout << a << " " << b << " " << c << "\n";

    // sometimes more useful:
    for (int i = 0, j = 10 /* usual variable declaration */; i <= j;
         i++, j-- /* comma operator */) {
        std::cout << i << " " << j << "\n";
    }
}
