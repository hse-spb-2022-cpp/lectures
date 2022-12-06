#include <cassert>
#include <iterator>
#include <iostream>

int main() {
    // GCC/Clang extension in C++ (available in C99): Variable Length Array (VLA).
    // Not available in other compilers.
    // https://gcc.gnu.org/onlinedocs/gcc/Variable-Length.html
    int n;
    std::cin >> n;
    int vla[n];  // Allocated "on stack"
    std::cout << sizeof(vla) / sizeof(vla[0]) << "\n";
    // std::cout << std::size(vla) << "\n";  // Does not compile because there is no exact "type" for VLA to instantiate std::size with.
    for (int i = 0; i < n; i++) {
        vla[i] = i * i;
    }
    for (int x : vla) {
        std::cout << " " << x;
    }
    std::cout << "\n";
}
