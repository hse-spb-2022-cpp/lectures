#include <iostream>

void foo() {
    std::cout << "foo global\n";
}

namespace ns1 {
int x;

void foo() {
    std::cout << "foo1\n";
}
}  // namespace ns1

namespace ns2 {
void foo() {
    std::cout << "foo2\n";
}
}  // namespace ns2

int main() {
    foo();
    ::foo();
    ns1::foo();
    ns2::foo();
    ns1::x = 10;
}
