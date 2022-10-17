#include <iostream>
#include "other.hpp"

void foo() {
    std::cout << "main foo\n";
}

int main() {
    foo();
    do_other();
}
