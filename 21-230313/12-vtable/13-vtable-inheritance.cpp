#include <functional>
#include <iostream>
#include <vector>

struct Base;

struct BaseVtable {
    using print_impl_ptr = void (*)(Base *);
    print_impl_ptr print_ptr;

    // We may also add other information about type, e.g.:
    // std::string type_name;
};

struct Base {
    static const BaseVtable BASE_VTABLE;

    const BaseVtable *vptr = &BASE_VTABLE;
    int x = 10;

    static void print_impl(Base *b) {
        std::cout << "x = " << b->x << "\n";
    }

    void print() {
        vptr->print_ptr(this);
    }
};
const BaseVtable Base::BASE_VTABLE{Base::print_impl};

struct Derived;
struct DerivedVtable : BaseVtable {
    using mega_print_impl_ptr = void (*)(Derived *);
    mega_print_impl_ptr mega_print_ptr;
};

struct Derived : Base {
    static const DerivedVtable DERIVED_VTABLE;

    int y = 20;

    static void print_impl(Base *b) {
        Derived *d = static_cast<Derived *>(b);
        std::cout << "x = " << d->x << ", y = " << d->y << "\n";
    }

    static void mega_print_impl(Derived *b) {
        std::cout << "megapring! y = " << b->y << "\n";
    }

    Derived() {
        vptr = &DERIVED_VTABLE;
    }

    void mega_print() {
        static_cast<const DerivedVtable *>(vptr)->mega_print_ptr(this);
    }
};
const DerivedVtable Derived::DERIVED_VTABLE{Derived::print_impl,
                                            Derived::mega_print_impl};

struct SubDerivedVtable : DerivedVtable {
    // no new "virtual" functions
};
struct SubDerived : Derived {
    static SubDerivedVtable SUBDERIVED_VTABLE;

    int z = 20;

    static void mega_print_impl(Derived *b) {
        SubDerived *sd = static_cast<SubDerived *>(b);
        std::cout << "megaprint! y = " << sd->y << ", z = " << sd->z << "\n";
    }

    SubDerived() {
        vptr = &SUBDERIVED_VTABLE;
    }
};
SubDerivedVtable SubDerived::SUBDERIVED_VTABLE{Derived::print_impl,
                                               SubDerived::mega_print_impl};

int main() {
    SubDerived sd;
    sd.print();
    // Base::print() -->
    //     vptr == &SUBDERIVED_VTABLE -->
    //     vptr->print_ptr == Derived::print_impl
    sd.mega_print();

    Derived &d = sd;
    d.print();
    d.mega_print();

    Base &b = sd;
    b.print();
    Base::print_impl(&sd);
}
