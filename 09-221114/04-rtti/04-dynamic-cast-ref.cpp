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
    {
        [[maybe_unused]] const Derived1 &d1 = dynamic_cast<const Derived1 &>(b);
        std::cout << "Derived1\n";
    }
    {
        const SubDerived1 &md1 = dynamic_cast<const SubDerived1 &>(b);
        std::cout << "SubDerived1 " << md1.value << "\n";
    }
}

int main() {
    SubDerived1 sd1;
    Derived2 d2;
    f(sd1);
    f(d2);  // exception thrown
}
