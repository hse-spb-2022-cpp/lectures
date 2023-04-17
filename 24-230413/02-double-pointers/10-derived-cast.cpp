struct Base {};
struct Derived : Base {};
struct Derived2 : Base {};

int main() {
    Base b;
    Derived d;
    [[maybe_unused]] Derived2 d2;

    {
        [[maybe_unused]] Base *pb = &b;
        [[maybe_unused]] Derived *pd = &d;
        pb = pd;  // Derived* --> Base*: OK

        pb = &d2; // OK
        // pd = pb;  // Base* --> Derived*: error, otherwise pd points to Derived2.
    }
    {
        Base *pb = &b;
        [[maybe_unused]] Base **ppb = &pb;
        Derived *pd = &d;
        [[maybe_unused]] Derived **ppd = &pd;

        *ppb = &d2;  // OK
        // ppd = ppb;  // Base** --> Derived**: error, otherwise *ppd points to Derived2.

        // Surprise: https://isocpp.org/wiki/faq/proper-inheritance#derivedptrptr-to-baseptrptr
        // ppb = ppd;  // Derived** --> Base**: error, otherwise assertion fails:
        *ppb /* Base* */ = &d2;  // OK
        // assert(*ppd /* Derived* */ != &d2 /* Derived2* */);
    }
}
