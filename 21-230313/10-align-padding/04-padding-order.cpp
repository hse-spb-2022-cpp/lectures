#include <iostream>

struct Foo {
    char c = 0;
    // padding
    int i = 0;
    char c2 = 0;
};

struct Bar {
    int i = 0;
    char c = 0;
    char c2 = 0;
    // padding
};

int main() {
    Foo f;
    std::cout << sizeof(Foo) << "\n";
    std::cout << static_cast<void *>(&f.c) << "\n";
    std::cout << &f.i << "\n";
    std::cout << static_cast<void *>(&f.c2) << "\n";

    std::cout << sizeof(Bar) << "\n";
    Bar b;
    std::cout << &b.i << "\n";
    std::cout << static_cast<void *>(&b.c) << "\n";
    std::cout << static_cast<void *>(&b.c2) << "\n";
}
