#include <iostream>

struct Foo {
    int value;
    Foo(int value_) : value(value_) {
        std::cout << "Foo(" << value << ") " << this << "\n";
    }
    ~Foo() {
        std::cout << "~Foo(" << value << ") " << this << "\n";
    }
};

Foo calc() {
    Foo x = Foo(20).value + Foo(30).value;
    return x;
}

int main() {
    Foo f(10);
    std::cout << "f created\n";
    Foo g = calc().value + Foo(40).value + Foo(50).value;
    std::cout << "g created\n";
}
