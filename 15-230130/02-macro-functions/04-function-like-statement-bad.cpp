#include <iostream>

#define print_twice(x) { std::cout << x; std::cout << x; }

int main() {
    if (2 * 2 == 4)
        print_twice(55);
    else
        print_twice(123);
}
