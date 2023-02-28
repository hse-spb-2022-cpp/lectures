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

// Cases:
// 1. Base's member or constructor throws
// 2. Derived's member or constructor throws
struct Base {
    with_destructor<1> a;
    with_destructor<2, true> b;

    Base() {
        std::cout << "Base()\n";
    }
    ~Base() {
        std::cout << "~Base()\n";
    }
};

struct Derived : Base {
    with_destructor<3> c;
    with_destructor<4> d;
    Derived() /* : Base() */ {
        std::cout << "Derived()\n";
    }
    ~Derived() {
        std::cout << "~Derived()\n";
    }
};

int main() {
    try {
        with_destructor<0> x;
        Derived d;
    } catch (...) {
        std::cout << "Caught\n";
    }
}
