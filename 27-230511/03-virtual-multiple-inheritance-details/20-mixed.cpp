#include <iostream>

struct Base { int data = 0; };
struct X : virtual Base {};
struct Y : virtual Base {};
struct Z : Base {};
struct Derived : X, Y, Z {};

int main() {
    Derived d;
    // d.data = 5;  // ambiguous
    // Base &b = d;  // ambiguous
    d.X::data = 10;
    d.Z::data = 20;

    [[maybe_unused]] Base &bxy = static_cast<X&>(d);
    [[maybe_unused]] Base &bz = static_cast<Z&>(d);

    std::cout << d.X::data << "\n";
    std::cout << d.Y::data << "\n";
    std::cout << d.Z::data << "\n";

    // In general:
    // 1. For each base B: at most one virtual B, arbitrary number of non-virtual.
    // 2. Order of initialization: all virtuals (from base to derived), everything else
    // 3. Order of deinitialization: reverse.
}
