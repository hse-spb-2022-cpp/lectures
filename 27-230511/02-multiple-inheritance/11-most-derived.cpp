#include <string>
#include <iostream>

/*
 X        Y
 ^        ^
  \      /
   \    /
  Derived
*/

struct X { int x_data = 0; virtual ~X() {} };
struct Y { int y_data = 0; virtual ~Y() {} };
struct Derived : X, Y { };

int main() {
    alignas(0x100) Derived d;
    X &x = d;
    Y &y = d;

    std::cout << &d << "\n";
    std::cout << &x << " " << dynamic_cast<void*>(&x) << "\n";  // "most derived object"
    std::cout << &y << " " << dynamic_cast<void*>(&y) << "\n";  // "most derived object"
}
