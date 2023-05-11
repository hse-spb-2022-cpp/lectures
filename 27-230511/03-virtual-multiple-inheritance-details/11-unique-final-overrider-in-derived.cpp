#include <iostream>

struct Base {
    virtual void foo() = 0;
    virtual void bar() = 0;
};

struct X : virtual Base {
    void foo() override {
        std::cout << "X::foo()\n";
    }
};

struct Y : virtual Base {
    void foo() override {
        std::cout << "Y::foo()\n";
    }
    void bar() override {
        std::cout << "Y::bar()\n";
    }
};

struct Derived : X, Y {  // ok: Derived::foo() calls X::foo() + Y::foo(), Y::bar()
    void foo() override {
        std::cout << "Derived::foo()\n";
        X::foo();  // non virtual call
        Y::foo();  // non virtual call
    }
};

int main() {
    Derived d;
    d.foo();
    std::cout << "=====\n";
    d.bar();
    std::cout << "=====\n";
    static_cast<Base&>(d).foo();  // Derived::foo()
    std::cout << "=====\n";
    d.X::foo();  // non virtual call
}
