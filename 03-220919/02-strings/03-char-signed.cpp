#include <cctype>
#include <iostream>

int main() {
    char c1 = -10;  // can be either signed or signed, typically signed
    unsigned char c2 = c1;  // always unsigned
    signed char c3 = c1;  // always signed
    std::cout << static_cast<int>(c1) << '\n';
    std::cout << static_cast<int>(c2) << '\n';
    std::cout << static_cast<int>(c3) << '\n';

    std::vector<int> vec(256);
    vec[c1] = 5;  // oops, UB
    vec[static_cast<unsigned char>(c1)] = 5;  // ok

    // https://en.cppreference.com/w/cpp/string/byte/isspace
    std::cout << std::isspace(c1) << '\n';  // oops, UB: expects `unsigned char` or `int`
}
