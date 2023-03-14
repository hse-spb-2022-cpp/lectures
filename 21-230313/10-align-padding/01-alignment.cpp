#include <cassert>
#include <iostream>

int main() {
    long long x = 10;
    std::cout << x << "\n";
    std::cout << sizeof(x) << " " << alignof(x) << "\n";
    assert(sizeof(x) % alignof(x) == 0);
    std::cout << &x << "\n";
}
