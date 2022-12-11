#include <iostream>

struct Base {
    int value = 123;

    virtual void foo() {
        std::cout << "foo(" << value << ")\n";
    };

    Base() {
        foo();
    }

    ~Base() {
        foo();
    }
};

struct Derived : Base {
    int value2 = 456;

    void foo() override {
        std::cout << "foo(" << value << ", " << value2 << ")\n";
    }

    Derived() : Base(), value2(100) {
        foo();
    }

    ~Derived() {
        foo();
    }
};

int main() {
    Derived d;
    std::cout << "== constructed ==\n";
    d.foo();
    static_cast<Base &>(d).foo();
    std::cout << "== foo called ==\n";
}
