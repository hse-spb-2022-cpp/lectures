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

void foo_and_print(const Base &b) {
    b.foo();
    // b.bar();
    std::cout << "x=" << b.x << "\n";
}

int main() {
    {
        Derived d;
        std::cout << "Via reference\n";
        foo_and_print(d);

        Base &b = d;  // basecast (C++), upcast (другие языки).
        b.foo();
        // b.bar();
        b.x++;
        std::cout << "d.x=" << d.x << "\n";
    }
    {
        Derived d;
        std::cout << "Via pointer\n";

        Derived *dptr = &d;
        Base *bptr = dptr;
        bptr->foo();
        // bptr->bar();
        std::cout << "b.x=" << bptr->x << "\n";
        bptr->x++;
        std::cout << "d.x=" << d.x << "\n";

        std::cout << dptr << " " << bptr << "\n";
        std::cout << &d.x << " " << &d.y << "\n";
    }
    std::cout << sizeof(Base) << " " << sizeof(Derived) << "\n";
}
