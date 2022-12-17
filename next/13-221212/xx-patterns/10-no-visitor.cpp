#include <exception>
#include <iostream>
#include <memory>

struct Base {
    virtual void op1() = 0;
    virtual void op2() = 0;
};

struct Derived1 : Base {
    void op1() override {
        std::cout << "d1op1\n";
    }
    void op2() override {
        std::cout << "d1op2\n";
    }
};

struct Derived2 : Base {
    void op1() override {
        std::cout << "d2op1\n";
    }
    void op2() override {
        std::cout << "d2op2\n";
    }
};

void op3(Base &b) {
    // Slow, is not checked for exhaustiveness by the compiler.
    if (dynamic_cast<Derived1 *>(&b)) {
        std::cout << "d1op3\n";
    // } else if (dynamic_cast<Derived2 *>(&b)) {
    //    std::cout << "d2op3\n";
    } else {
        std::terminate();
    }
}

int main() {
    // If we want new operation, we add a virtual function everywhere.
    // We are free to add Derived3, Derived4 without changing existing code.
    std::unique_ptr<Base> d1 = std::make_unique<Derived1>();
    std::unique_ptr<Base> d2 = std::make_unique<Derived2>();

    d1->op1();
    d1->op2();
    op3(*d1);
    d2->op1();
    d2->op2();
    op3(*d2);
}
