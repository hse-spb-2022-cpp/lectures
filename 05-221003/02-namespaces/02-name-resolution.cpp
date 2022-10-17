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
    bar();  // unqualified name lookup for 'bar': look at ns1, ::
    some_global();  // unqualified name lookup: look at ns1, ::

    // same, becase 'ns1' is only in the global namespace
    ns1::bar();  // unqualified name lookup for 'ns1': look as ns1, :: (found).
                 // qualified name lookup for 'bar' inside 'ns1': found
    ::ns1::bar();  // qualified name lookup for 'ns1' inside ::
                   // qualified name lookup for 'bar' inside 'ns1': found

    // different, because 'foo' exists both in 'ns1' and global
    foo();  // unqualified name lookup: look at ns1 (found, infinite recursion)
    ::foo();  // qualified name lookup with global namespace
}
}  // namespace ns1

int main() {
    foo();
    ::foo();
    ns1::foo();
    ::ns1::foo();
}
