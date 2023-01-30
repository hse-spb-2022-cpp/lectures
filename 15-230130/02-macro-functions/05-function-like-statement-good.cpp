#include <iostream>

// https://stackoverflow.com/questions/923822/whats-the-use-of-do-while0-when-we-define-a-macro
#define print_twice(x) do { std::cout << x; std::cout << x; } while (0)

int main() {
    if (2 * 2 == 5)
        print_twice(55);
    else
        print_twice(123);

    // Cannot be fixed.
    print_twice(10), print_twice(20);
}
