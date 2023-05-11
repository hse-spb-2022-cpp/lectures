#include <iostream>

struct Base {
    virtual void foo() = 0;
    virtual void bar() = 0;
};

struct X : virtual Base {
    void foo() override {
        std::cout << "X::foo()\n";
        bar();  // https://isocpp.org/wiki/faq/multiple-inheritance#mi-delegate-to-sister
    }
};

struct Y : virtual Base {
    void bar() override {
        std::cout << "Y::bar()\n";
    }
};

struct Derived : X, Y {
};

int main() {
    Derived a;
    a.foo();  // X::foo() --> Base::bar() ~~ Y::bar()
}
