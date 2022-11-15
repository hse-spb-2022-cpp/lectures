#include <cassert>

struct Base {
    int x;
    Base(int x_) : x(x_) {}
};

struct Derived : Base {
    int y = 20;

    Derived() : Base(10) {}
//    Derived(int y_) : y(y_), Base(y) {}  // -Wreorder, UB: read from uninitialized field
//    Derived(int y_) : Base(y), y(y_) {}  // UB is apparent
    Derived(int y_) : Base(y_), y(y_) {}  // OK
};

struct SubDerived : Derived {
    SubDerived(int) {}  // : Derived() is implied.
};

struct DerivedNaive : Base {
};

int main() {
    Derived d;
    assert(d.x == 10);

    // DerivedNaive dn(10);  // Конструкторы не наследуются.
}
