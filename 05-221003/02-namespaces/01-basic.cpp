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

namespace sub {
void foo() {
    std::cout << "foo3\n";
}
}
}  // namespace ns2

namespace ns3 {}

int main() {
    foo();  // unqualified name lookup
    ns1::foo();  // unqualified name lookup + qualified
    ns2::foo();
    ns2::sub::foo();  // unqualified name lookup + qualified + qualified
    ns1::x = 10;
    // ns3::foo();  // compilation error
}
