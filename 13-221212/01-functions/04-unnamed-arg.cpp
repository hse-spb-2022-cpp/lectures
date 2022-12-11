#include <iostream>

// [[]] is an 'attribute', since C++17
void foo([[maybe_unused]] int x) {
    std::cout << "foo(int)\n";
}

void foo(int x, int) {
    std::cout << "foo(int x, int) x=" << x << "\n";
}

int main() {
    foo(10);
    foo(10, 20);
}
