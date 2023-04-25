#include <iostream>

int main() {
    int i = 123;
    char a = 'X';

    std::cout << i << "\n";  // 123
    std::cout << &i << "\n";  // address of 'i'

    std::cout << a << "\n";  // X
    // std::cout << &a << "\n";  // UB, because `char*` is interpreted as ASCIIZ string
    std::cout << static_cast<void*>(&a) << "\n";  // ok, address of 'a'
}
