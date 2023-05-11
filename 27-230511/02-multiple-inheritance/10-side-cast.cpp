#include <iostream>
#include <cstddef>

struct Base1 { virtual ~Base1() {} };
struct Base2 { virtual ~Base2() {} };
struct Base3 { virtual ~Base3() {} };
struct Derived123 : Base1, Base2, Base3 {};

struct CompletelyUnrelated {};

void foo(Base1 &b1) {
    std::cout << dynamic_cast<Base3*>(&b1) << "\n";
    std::cout << dynamic_cast<CompletelyUnrelated*>(&b1) << "\n";
}

int main() {
    Derived123 a;
    std::cout << "Derived123 " << &a << "\n";
    foo(a);

    struct Derived123C : Derived123, CompletelyUnrelated {};
    Derived123C b;
    std::cout << "Derived123C " << &b << "\n";
    foo(b);
}
