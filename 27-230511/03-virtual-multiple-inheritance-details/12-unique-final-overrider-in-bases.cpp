#include <iostream>

struct Base {
    virtual void foo() { std::cout << "Base::foo()\n"; }
    virtual void bar() = 0;
};

struct X : virtual Base {
    void foo() override {
        std::cout << "X::foo()\n";
    }
};

struct Y : virtual Base {
//    void foo() override {
//        std::cout << "Y::foo()\n";
//     }
    void bar() override {
        std::cout << "Y::bar()\n";
    }
};

struct Derived : X, Y {  // ok: X::foo(), Y::bar()
};

int main() {
    Derived d;
    d.foo();
    d.bar();
}
