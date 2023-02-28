#include <iostream>

struct Base {
    ~Base() noexcept(false) {
        throw 0;
    }
};

struct Foo : Base {
    ~Foo() try {
        std::cout << "destructing Foo\n";
    } catch (...) {
        // Catching exceptions from: destructors of fields and bases.
        // All fields and bases are already destroyed.
        // We do not know what exactly has failed.

        std::cout << "destruction exception\n";
        // `throw;` is added implicitly, but if we `return`, the destructor is considered not throwing.
        return;
    }
};

int main() {
    try {
        Foo f;
    } catch (...) {
        std::cout << "exception\n";
    }
}
