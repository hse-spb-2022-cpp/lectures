#include <iostream>

int main() {
    char a = 'x';
    char *a_str_bad = &a;
    char b[2] = "hi";

    std::cout << a_str_bad << "\n";  // ub: out of bounds
    std::cout << b << "\n";  // ub: out of bounds
}