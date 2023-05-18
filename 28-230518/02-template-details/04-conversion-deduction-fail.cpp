#include <iostream>
#include <string>

template<typename T>
void print_two(const T &a, const T &b) {
    std::cout << a << " " << b << std::endl;
}

int main() {
    print_two<std::string>(std::string("hello"), "world");
    // print_two<>(std::string("hello"), "world");  // compilation error: conflicting types
}
