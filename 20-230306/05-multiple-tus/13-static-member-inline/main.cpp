#include <iostream>

struct Foo {
    static inline int value = 10;
};

void foo();

int main() {
    std::cout << "From main()\n";
    std::cout << Foo::value << " " << &Foo::value << "\n";
    foo();
}
