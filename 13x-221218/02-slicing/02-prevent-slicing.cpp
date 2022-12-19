#include <iostream>

struct Base {
    int x = 10;
    void foo() const {
        std::cout << "x=" << x << "\n";
    }

    Base() {}
    Base(const Base &) = delete;
    Base(Base &&) = delete;
    Base &operator=(const Base &) = delete;
    Base &operator=(Base &&) = delete;
    virtual ~Base() {}
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
        bar(d);
    }
    {
        Base b;
        bar(b);
    }
}
