struct Base {
    void foo() {
    }
};

struct Derived1 : public Base {};  // Default for 'struct', the most popular.
struct Derived2 : protected Base {};
struct Derived3 : private Base {  // Default for 'class'.
    void baz() {
        foo();
        Derived3 d3;
        [[maybe_unused]] const Base &b = d3;
    }
};

struct Derived22 : /* public */ Derived2 {
    void bar() {
        foo();
        Derived2 d2;
        [[maybe_unused]] const Base &b2 = d2;
    }
};

struct Derived33 : /* public */ Derived3 {
    void bar() {
        // foo();
        [[maybe_unused]] ::Base b;  // :: is important
        // [[maybe_unused]] const ::Base &b2 = *this;
        // [[maybe_unused]] const ::Base &b3 = static_cast<const ::Base &>(*this);
        [[maybe_unused]] const ::Base &b4 =
            (const ::Base
                 &)*this;  // meh, C-style cast ignores access modifiers
    }
};

int main() {
    Base b;
    Derived1 d1;
    Derived2 d2;
    Derived3 d3;

    b.foo();
    d1.foo();
    // d2.foo();
    // d3.foo();

    [[maybe_unused]] const Base &b1 = d1;

    // [[maybe_unused]] const Base &b2x = d2;
    // [[maybe_unused]] const Base &b2y = static_cast<const Base &>(d2);
    [[maybe_unused]] const Base &b2z =
        (const Base &)d2;  // meh, C-style cast ignores access modifiers

    // [[maybe_unused]] const Base &b3x = d3;
    // [[maybe_unused]] const Base &b3y = static_cast<const Base &>(d3);
    [[maybe_unused]] const Base &b3z =
        (const Base &)d3;  // meh, C-style cast ignores access modifiers
}
