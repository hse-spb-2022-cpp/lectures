#include "print.h"
#include <iostream>

// ODR and linkage error if commented: two instances of print.
// ODR and linkage error if uncommented: two instances of print.
#if 1
template<>
void print(const int &value) {
    std::cout << "foo " << value << "\n";
}
#endif

void foo() {
    print(2);
    print(2.3);
}