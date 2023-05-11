#include <iostream>

struct Base { int data = 0; };
struct X : virtual Base {};
struct Y : Base {};
struct Z : virtual Base {};
struct Derived : X, Y, Z {};  // warning: multiple 'Base'

/*
    Base 
  v.|  |v.
  -/   \
 /      -----\
X             Z
|     Base   /
|      |    /
|      Y   /
 \--\  |  /
    Derived
*/

int main() {
    Derived d;
    // d.data = 5;  // ambiguous
    // Base &b = d;  // ambiguous
    d.X::data = 10;
    d.Y::data = 20;
    // d.Base::data = 123;  // ambiguous

    std::cout << d.X::data << "\n";
    std::cout << d.Y::data << "\n";
    std::cout << d.Z::data << "\n";

    [[maybe_unused]] Base &bxz = static_cast<X&>(d);
    [[maybe_unused]] Base &by = static_cast<Y&>(d);

    // In general:
    // 1. For each base B: at most one virtual B, arbitrary number of non-virtual.
    // 2. Order of initialization: all virtuals (from base to derived), everything else
    // 3. Order of deinitialization: reverse.
}
