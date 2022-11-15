#include <boost/core/demangle.hpp>
#include <iostream>
#include <set>
#include <typeindex>
#include <typeinfo>
#include <vector>

// RTTI is for polymorphic classes only.
struct Base {
    virtual ~Base() {
    }
};

struct Derived : Base {};

int main() {
    Base b;
    Derived d;

    const std::type_info &info_base = typeid(Base);
    const std::type_info &info_derived = typeid(Derived);
    using DerivedAlias = Derived;
    const std::type_info &info_derived_alias = typeid(DerivedAlias);

    const std::type_info &info_b = typeid(b);
    const std::type_info &info_d = typeid(d);

    std::cout << (info_base == info_b) << "\n";                 // 1
    std::cout << (info_base == info_d) << "\n";                 // 0
    std::cout << (info_derived == info_b) << "\n";              // 0
    std::cout << (info_derived == info_d) << "\n";              // 1
    std::cout << (info_derived == info_derived_alias) << "\n";  // 1

    std::cout << typeid(int).name() << "\n";  // 'i' (msys2) pr 'int' (VS)
    std::cout << info_b.name() << "\n";       // '4Base' or 'struct Base' (VS)
    std::cout << typeid(std::vector<int>).name()
              << "\n";  // 'St6vectorIiSaIiEE' or something else in VS

    // type_info is not copyable or <> comparable
    // std::type_info x = info_base;
    // Since C++11:
    std::set<std::type_index> types{info_base, info_derived, info_b,
                                    info_d};  // C++11
    for (const auto &t : types) {
        std::cout << "t=" << t.name() << "\n";
    }
}
