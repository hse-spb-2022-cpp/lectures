#include <iostream>
#include "foo.hpp"

int main() {
    std::cout << "main sees: " << get_foo().x << "\n";
}
