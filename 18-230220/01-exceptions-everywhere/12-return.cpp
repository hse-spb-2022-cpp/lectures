#include <iostream>

int remaining = 1;

struct Foo {
    Foo() {
        std::cout << "Foo() " << this << "\n";
    }
    Foo(const Foo &) {
        std::cout << "Foo(const Foo&) " << this << "\n";
        if (!--remaining) {
            throw 0;
        }
    }
    Foo &operator=(const Foo&) = delete;
    ~Foo() {
        std::cout << "~Foo " << this << "\n";
    }
};

Foo func(int x) {
    Foo a, b;
    // We need some convoluted code so the compiler cannot use RVO/NRVO (optimizations).
    if (x == 0) {
        try {
            return a;
        } catch (...) {
            std::cout << "exception in func\n";
            return Foo();
        }
    } else {
        return b;
    }
}

int main() {
    Foo f = func(0);
    std::cout << "&f=" << &f << "\n";
}
