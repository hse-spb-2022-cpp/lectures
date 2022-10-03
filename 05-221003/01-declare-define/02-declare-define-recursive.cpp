#include <iostream>

void bar(int n);  // declaration, объявление

void foo(int n) {  // definition, определение
    std::cout << "foo " << n << "\n";
    bar(n - 1);
}

void bar(int n) {  // definition, определение
    std::cout << "bar " << n << "\n";
    if (n == 0) {
        return;
    }
    foo(n - 1);
}

int main() {
    bar(10);
}
