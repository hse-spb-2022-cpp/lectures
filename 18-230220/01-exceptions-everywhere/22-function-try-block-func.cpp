#include <iostream>

int remaining = 2;

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

Foo func(Foo a, Foo, Foo) try {
    std::cout << "func\n";
    return a;
} catch (...) {
    // Does not catch exceptions on argument creation.
    // The rest can be caught with the usual `try`-`catch`,
    // including `return`. So: useless.
    std::cout << "exception in func!\n";
    // No implicit `throw;`, we `return` normally by default.
    throw;
}

int main() {
    Foo a, b, c;
    try {
        std::cout << "before foo\n";
        Foo x = func(a, b, c);
        std::cout << "after foo\n";
    } catch (...) {
        std::cout << "exception\n";
    }
}
