#include <iostream>
#include <memory>

// Kind of
// https://ru.wikipedia.org/wiki/%D0%9F%D0%BE%D1%81%D0%B5%D1%82%D0%B8%D1%82%D0%B5%D0%BB%D1%8C_(%D1%88%D0%B0%D0%B1%D0%BB%D0%BE%D0%BD_%D0%BF%D1%80%D0%BE%D0%B5%D0%BA%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D1%8F)
struct BaseVisitor;
struct Base {
    virtual void op1() = 0;
    virtual void op2() = 0;

    virtual void accept(BaseVisitor &) = 0;
};

struct Derived1;
struct Derived2;

struct BaseVisitor {
    virtual void visit(Derived1 &d1) = 0;
    virtual void visit(Derived2 &d2) = 0;
};

struct Derived1 : Base {
    void op1() override {
        std::cout << "d1op1\n";
    }
    void op2() override {
        std::cout << "d1op2\n";
    }
    void accept(BaseVisitor &v) override {
        v.visit(*this);
    }
};

struct Derived2 : Base {
    void op1() override {
        std::cout << "d2op1\n";
    }
    void op2() override {
        std::cout << "d2op2\n";
    }
    void accept(BaseVisitor &v) override {
        v.visit(*this);
    }
};

struct Op3 : BaseVisitor {
    void visit(Derived1 &) override {
        std::cout << "d1op3\n";
    }
    void visit(Derived2 &) override {
        std::cout << "d2op3\n";
    }
};

int main() {
    // If we want to add Derived3, Derived4 we add a virtual function to all
    // visitors. We are free to add new visitors (operations) without changing
    // existing code.
    std::unique_ptr<Base> d1 = std::make_unique<Derived1>();
    std::unique_ptr<Base> d2 = std::make_unique<Derived2>();

    Op3 op3;
    // op3.visit(*d1);  // Should be resolved during compilation, unable.

    d1->op1();
    d1->op2();
    d1->accept(op3);
    d2->op1();
    d2->op2();
    d2->accept(op3);
}
