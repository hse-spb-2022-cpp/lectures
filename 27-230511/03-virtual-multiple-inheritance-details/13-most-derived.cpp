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
    virtual ~Base() {}
};
struct X : virtual Base { int x_data = 0; };
struct Y : virtual Base { int y_data = 0; };
struct Derived : X, Y { };

int main() {
    alignas(0x100) Derived d1;
    Base &b1 = d1;

    std::cout << &d1 << "\n";
    std::cout << &b1 << "\n";
    std::cout << dynamic_cast<void*>(&b1) << "\n";  // "most derived object"
    // Usage: custom memory deallocation
}
