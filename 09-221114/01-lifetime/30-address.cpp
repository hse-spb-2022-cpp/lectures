#include <cassert>
#include <iostream>

int x1, x2, x3;

int main() {
    int y1, y2, y3;
    int *z = new int;

    std::cout << &x1 << " " << &x2 << " " << &x3 << "\n";
    std::cout << &y1 << " " << &y2 << " " << &y3 << "\n";
    std::cout << &z << "\n";
    std::cout << z << "\n";

    std::cout << (&x1 == z) << "\n";  // ok

    // All are unspecified behavior (returns _something_, but not guaranteed to be consistent).
    std::cout << (&x1 < z) << "\n";
    std::cout << (&x1 < &x2) << "\n";

    int arr[10];
    int *a2 = &arr[2];
    int *a5 = &arr[5];
    assert(a2 < a5);  // Always true: both inside the same array.

    delete z;
}
