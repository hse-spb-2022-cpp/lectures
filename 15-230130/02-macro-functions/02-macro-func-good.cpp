#include <iostream>

#define max(a, b) ((a) < (b) ? (a) : (b))
#define mul(a, b) ((a) * (b))

int foo() {
    std::cout << "foo() evaluated\n";
    return 10;
}

int main() {
    std::cout << max(2, 1) << "\n";  // No brackets => ((std::cout << 2) < 1) ? 2 : 1 << "\n";
    std::cout << mul(2 + 1, 2) << "\n";  // No brackets => 2 + 1 * 2

    int x = 10;
    std::cout << max(x++, 12) << "\n";  // Macro => double change of 'x' => UB.
    std::cout << max(foo(), 12) << "\n";  // Macro => double evaluation of foo().
}
