#include <iostream>

struct Base {
    int x = 10;
    void foo() const {
        std::cout << "x=" << x << "\n";
    }
};

struct Derived : Base {
    int y = 20;
    void bar() const {
        foo();
        std::cout << "y=" << y << "\n";
    }
};

void foo(const Base &b) {
    std::cout << "foo(" << b.x << ")\n";
    const Derived &d = static_cast<const Derived&>(b);  // derivedcast (C++), downcast (others).
    std::cout << ".y=" << d.y << "\n";
}

int main() {
    {
        Derived d;
        foo(d);  // Not UB: d is really Derived.
    }
    {
        Base b;
        foo(b);  // UB!
    }
}
