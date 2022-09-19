#include <cassert>
#include <iostream>
#include <string>

void append(std::string &s) {
    s += 'x';
}

void print_appended(const std::string &s) {
    std::cout << s << 'x';
}

int main() {
    std::string s = "hello";
    append(s);
    std::cout << s << '\n';  // hellox

    append(s + "world");  // compilation error: temporary object
    append(std::string("world"));  // compilation error: temporary object

    print_appended(std::string("world"));  // ok
    std::cout << '\n';
}
