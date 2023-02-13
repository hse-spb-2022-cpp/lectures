#include <iostream>

void check_n(int n) {
    if (n < 0) {
        throw 0;
    }
}

void foo() noexcept {  // If exception: std::terminate(), no dtor calls
    std::cout << "foo() start\n";
    int n;
    std::cin >> n;
    check_n(n);
    std::cout << "foo() end\n";
}

int main() {
    try {
        foo();
    } catch (...) {
        std::cout << "Caught\n";
    }
}
