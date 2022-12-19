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

void bar(Base b) {  // Slicing: we create a new object
    std::cout << "bar(" << b.x << ")\n";
    const Derived &d = static_cast<const Derived&>(b);  // derivedcast, UB
    std::cout << ".y=" << d.y << "\n";  // UB
    &d.y;  // UB
}

int main() {
    {
        Derived d;
        d.x = 123;
        // Base(const Base &other) : x(other.x)
        bar(d);  // Always UB.
    }
    {
        Base b;
        bar(b);  // Always UB.
    }
}
