#include <iostream>

int a = 10;

void foo(const int &x) {
    std::cout << x << "\n";
    a++;
    std::cout << x << "\n";
}

int main() {
    foo(a);
}
