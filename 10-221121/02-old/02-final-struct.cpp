#include <algorithm>

struct Base {};

struct Derived1 final : Base {
    int value = 123;
};

// struct SubDerived : Derived1 {};  // impossible

// Two alternative strategies:
// 1. `final` all structs, unless you are sure there will be derived classes.
// "Safer" because you cannot inherit from someone who did not think about it.
// 2. `final` nothing, because you do not want to prohibit some "safe"
// inheritance where needed (see "mock objects").

struct Derived2 final : Base {
    int value = 456;
};

int main() {
}
