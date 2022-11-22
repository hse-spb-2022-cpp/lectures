#include <iostream>

struct Base {
    virtual ~Base(){};
};

struct Derived1 : Base {};

struct SubDerived1 : Derived1 {
    int value = 123;
};

struct Derived2 : Base {
    int value = 456;
};

void f(const Base &b) {
    std::cout << "====\n";
    // dynamic_cast only compiles if Base is "polymorphic" <=> has at least one
    // virtual method. Typically it's a virtual destructor.
    const Derived1 *d1 = dynamic_cast<const Derived1 *>(&b);
    if (d1)
        std::cout << "Derived1 or SubDerived1\n";
    if (typeid(b) == typeid(Derived1))
        std::cout << "Exactly Derived1\n";
    // d1 is visible

    if (const SubDerived1 *sd1 =
            dynamic_cast<const SubDerived1 *>(&b)) {  // C++03
        std::cout << "SubDerived1 " << sd1->value << "\n";
    }
    // sd1 is not visible

    if (const Derived2 *d2 = dynamic_cast<const Derived2 *>(&b);
        d2 != nullptr && d2->value > 10) {  // C++17: if with init statement
        std::cout << "Derived2 " << d2->value << " > 10\n";
    }
    // d2 is not visible
}

int main() {
    // RTTI (Run-Time Type-Information) is needed, it's sometimes disabled with
    // `-fno-rtti`.
    SubDerived1 sd1;
    Derived2 d2;
    f(sd1);
    f(d2);

    Base *b = nullptr;
    std::cout << dynamic_cast<const Derived1 *>(b) << "\n";
}
