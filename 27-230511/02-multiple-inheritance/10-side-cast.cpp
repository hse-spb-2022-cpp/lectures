#include <iostream>
#include <cstddef>

struct Base1 { int x = 1; virtual ~Base1() {} };
struct Base2 { int y = 2; virtual ~Base2() {} };
struct Base3 { int z = 3; virtual ~Base3() {} };
struct Derived123 : Base1, Base2, Base3 {};
/*
Base1  Base2  Base3
  ^      ^      ^
   \     |     /
    \    |    /
     Derived123
*/

struct CompletelyUnrelated {};

void foo(Base1 &b1) {
    std::cout << dynamic_cast<Base3*>(&b1) << "\n";  // side-cast/cross-cast
    if (auto *b3 = dynamic_cast<Base3*>(&b1)) {
        std::cout << "  z=" << b3->z << ", &z=" << &b3->z << "\n";
    }
    std::cout << dynamic_cast<CompletelyUnrelated*>(&b1) << "\n";
}

int main() {
    Derived123 a;
    std::cout << "Derived123 " << &a << ", &z=" << &a.z << "\n";
    foo(a);

    struct Derived123C : Derived123, CompletelyUnrelated {};
    /*
Base1  Base2  Base3
  ^      ^      ^
   \     |     /
    \    |    /
     Derived123  CompletelyUnrelated
         ^        ^
          \      /   
         Derived123C
*/
    Derived123C b;
    std::cout << "Derived123C " << &b << "\n";
    foo(b);
}
