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
        // Base1::foo();
        // Base2::foo();
        std::cout << "DerivedOverride\n";
    }
    // Cannot override 'Base1::foo()' and 'Base2::foo()' independently.
};

int main() {
    {
        std::cout << "===== DerivedSimple =====\n";
        DerivedSimple ds;
        ds.Base1::foo();  // non-virtual call
        ds.Base2::foo();  // non-virtual call
        // ds.foo();  // ambiguous
        static_cast<Base1&>(ds).foo();
        static_cast<Base2&>(ds).foo();
    }
    {
        std::cout << "===== DerivedOverride =====\n";
        DerivedOverride dorr;
        dorr.Base1::foo();  // non-virtual call
        dorr.Base2::foo();  // non-virtual call
        dorr.foo();  // non-ambiguous: the one from DerivedOverride
        static_cast<Base1&>(dorr).foo();
        static_cast<Base2&>(dorr).foo();
    }
}
