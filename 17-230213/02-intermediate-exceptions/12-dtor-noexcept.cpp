#include <iostream>

void maybe_throw() {
    static int remaining = 2;
    if (!--remaining) {
        throw 0;
    }
}

struct Foo {
    Foo() {
        std::cout << "Foo() " << this << "\n";
    }
    ~Foo() {
        std::cout << "~Foo() " << this << "\n";
        maybe_throw();
    }
};

int main() {
    try {
        try {
            Foo a;
            Foo b;
            Foo c;
            std::cout << "before throw\n";
            // TODO: split in C++03 and C++11
            throw 1;
            std::cout << "after throw\n";
        } catch (int x) {
            std::cout << "caught " << x << "\n";
        } catch (...) {
            std::cout << "caught something\n";
        }
    } catch (...) {
        std::cout << "caught outside\n";
    }
    // C++03: two exceptions simultanously => std::terminate().
    // C++11: dtors are noexcept, always std::terminate().
}
