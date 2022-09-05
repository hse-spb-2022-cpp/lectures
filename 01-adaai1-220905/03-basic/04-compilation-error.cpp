#include <iostream>

int main() {
    int a, b;
    a = "hello";  // compilation error: cannot assign string (`const char*` because legacy) to an `int` variable
    std::cin >> a >> b;
    std::cout << a + b << std::endl;
}
