#include <string>
#include <iostream>

/*
   Base
   ^  ^
  /    \
 /      \
X        Y
^        ^
 \      /
  \    /
 Derived
*/

struct Base {
    int base_data = 0;
    virtual ~Base() {}  // !!! need polymorphic class
};
struct X : virtual Base { int x_data = 0; };
struct Y : virtual Base { int y_data = 0; };
struct Derived : X, Y { };

int main() {
    alignas(0x100) Derived d1;
    X &x1 = d1;
    Base &b1 = d1;

    alignas(0x100) X x2;
    Base &b2 = x2;

    // d1: (baseptr x_data) (baseptr y_data) base_data
    // x2: (baseptr x_data) base_data

    std::cout << &x1 << " " << dynamic_cast<X*>(&b1) << " " << &b1 << "\n";
    std::cout << &x2 << " " << dynamic_cast<X*>(&b2) << " " << &b2 << "\n";
}
