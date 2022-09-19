#include <cassert>
#include <iostream>
#include <vector>

int main() {
    std::vector v{1, 2, 3};
    assert(v == std::vector{1, 2, 3});  // Compilation error because assert is a naive macro
    assert((v == std::vector{1, 2, 3}));  // OK
    assert(v == (std::vector{1, 2, 3}));  // OK
    std::cout << "OK\n";
}
