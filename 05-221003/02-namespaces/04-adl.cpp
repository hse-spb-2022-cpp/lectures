// Argument-Dependent Lookup aka Koenig Lookup
#include <algorithm>
#include <vector>

namespace ns_parent {
namespace ns {
struct Foo {};

void do_something() {}
void do_something(Foo) {}
bool operator==(const Foo&, const Foo&) { return true; }
};

void do_other(ns::Foo) {}
}

int main() {
    // do_something();
    ns_parent::ns::do_something();

    // Foo f;
    ns_parent::ns::Foo f;

    f == f;
    operator==(f, f);  // ok: unqualified lookup looks in argument's type's namespaces as well (ns_parent::ns)
    ns_parent::ns::operator==(f, f);

    ns_parent::ns::do_something(f);  // ok
    do_something(f);  // unqualified name lookup, ADL enabled

    ns_parent::do_other(f);  // ok
    // do_other(f);  // do_other is in another namespace, no ADL

    // Example:
    // getline(std::cin, str)
    // Better: std::getline

    std::vector<int> v{1, 2, 3};
    sort(v.begin(), v.end());  // v.begin() ~ std::vector<int>::iterator ~(?) int*
    // Better: std::sort
    // Probably not guaranteed at all: https://stackoverflow.com/questions/6803556/do-custom-container-iterators-guarantee-adl-to-consider-namespace-std
    // See https://quuxplusone.github.io/blog/2022/03/03/why-isnt-vector-iterator-just-t-star/
}
