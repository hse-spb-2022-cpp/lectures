#include <iostream>
#include <string>

template<typename T>
void print_two(const T &a, const T &b) {
    std::cout << a << " " << b << std::endl;
}

int main() {
    print_two<std::string>(std::string("hello"), "world");
    // print_two<>(std::string("hello"), "world");  // compilation error: conflicting types

    print_two<>("hello", "world");  // ok, both are char[6]
    print_two<>("hello111", "world");  // not ok: char[9], char[6]. But it's ok if 'T' instead of 'const &' because 'char*'.
}
