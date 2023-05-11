#include <iostream>

struct Base1 {
    virtual void foo() {
        std::cout << "Base1\n";
    }
};

struct Base2 {
    virtual void foo() {
        std::cout << "Base2\n";
    }
};

struct DerivedSimple : Base1, Base2 {
};

struct DerivedOverride : Base1, Base2 {
    void foo() override {  // Overrides both. Should be compatible in return value.
        std::cout << "DerivedOverride\n";
    }
};

int main() {
    {
        std::cout << "===== DerivedSimple =====\n";
        DerivedSimple ds;
        ds.Base1::foo();
        ds.Base2::foo();
        // ds.foo();  // ambiguous
        static_cast<Base1&>(ds).foo();
        static_cast<Base2&>(ds).foo();
    }
    {
        std::cout << "===== DerivedOverride =====\n";
        DerivedOverride dorr;
        dorr.Base1::foo();
        dorr.Base2::foo();
        dorr.foo();  // non-ambiguous: the one from DerivedOverride
        static_cast<Base1&>(dorr).foo();
        static_cast<Base2&>(dorr).foo();
    }
}
