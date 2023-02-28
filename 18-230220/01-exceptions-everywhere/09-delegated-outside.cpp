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
    with_destructor<3> c;
    with_destructor<4> d;

    Foo() {
        std::cout << "Foo()\n";
    }
    Foo(int) : Foo() {  // After a single ctor is completed, object is created.
        std::cout << "Foo(int)\n";
        std::cout << "throwing\n";
        throw 0;
    }
    ~Foo() {
        std::cout << "~Foo()\n";
    }
};

int main() {
    try {
        with_destructor<0> x;
        Foo f(10);
    } catch (...) {
        std::cout << "Caught\n";
    }
}
