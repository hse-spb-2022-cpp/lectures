#include <iostream>

void foo() {
    std::cout << "foo global\n";
}

void some_global() {
    std::cout << "some_global\n";
}

namespace ns1 {
void bar() {
    std::cout << "bar\n";
}

void foo() {
    std::cout << "foo1\n";
    bar();  // (!)
    some_global();  // (!)
    foo();  // infinite recursion
    ::foo();  // (!)
}
}  // namespace ns1

int main() {
    foo();
    ::foo();
    ns1::foo();
}
