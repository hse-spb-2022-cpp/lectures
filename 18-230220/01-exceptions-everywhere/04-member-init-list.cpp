#include <iostream>

template<int X, bool SHOULD_THROW = false>
struct with_destructor {
    with_destructor(bool should_throw = false) {
        std::cout << "constructing " << X << "\n";
        if (SHOULD_THROW || should_throw) {
            throw 0;
        }
    }
    ~with_destructor() {
        std::cout << "destructing " << X << "\n";
    }
};

struct Foo {
    with_destructor<1> a;
    with_destructor<2> b;
    with_destructor<3, true> c;
    with_destructor<4> d;

    Foo() : a(), b(true), c(), d() {
        std::cout << "Foo()\n";
    }
    ~Foo() {
        std::cout << "~Foo()\n";
    }
};

int main() {
    try {
        with_destructor<0> x;
        Foo f;
    } catch (...) {
        std::cout << "Caught\n";
    }
}
