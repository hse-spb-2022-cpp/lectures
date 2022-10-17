#include <iostream>

void foo() {
    std::cout << "foo global\n";
}

void some_global() {
    std::cout << "some_global\n";
}

namespace ns1 {
void bar() {
    std::cout << "ns1::bar()\n";
}

namespace ns2 {
void bar() {
    std::cout << "ns1::ns2::bar\n";
}
void botva_ns2() {
    std::cout << "ns1::ns2::botva_ns2()\n";
}
}  // namespace ns2

namespace ns3 {
void botva_ns3() {
    some_global();  // ok
    ns2::botva_ns2();  // ok, find 'ns2' first
    // botva_ns2();  // only looks up in ns1::ns3, ns1::, ::, not ns1::ns2
    std::cout << "ns1::ns3::botva_ns3()\n";
}
}  // namespace ns3

namespace ns3::ns4 {
namespace ns1 {  // ns1::ns3::ns4::ns1
}

void baz() {  // ns1::ns3::ns4
    botva_ns3();  // unqualified name lookup for 'botva_ns3'
    ns2::bar();  // unqualified name lookup for 'ns2', qualified name lookup bar()

    foo();  // ok, global
    // ns2::foo();  // compilation error: no 'foo' inside 'ns2'

    ::ns1::ns2::bar();  // fully qualified lookup
    // ns1::ns2::bar();  // thinks that 'ns1' is 'ns1::ns3::ns4::ns1', 'n2' not found
}
}  // namespace ns3::ns4
}  // namespace ns1

int main() {
    ns1::ns3::ns4::baz();
    ::ns1::ns3::ns4::baz();

    ::ns1::ns2::bar();  // ok
    ns1::ns2::bar();  // ok here, but not in ns1::ns3::ns4::baz()
}
