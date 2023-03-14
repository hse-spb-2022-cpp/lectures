#include <functional>
#include <iostream>
#include <vector>

struct Base;

struct BaseVtable {  // virtual functions table
    using print_impl_ptr = void (*)(Base *);
    print_impl_ptr print_ptr;
    // pretty_print_impl_ptr pretty_print_ptr;
    // read_impl_ptr read_ptr;

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

struct Derived : Base {
    static const BaseVtable DERIVED_VTABLE;

    int y = 20;

    static void print_impl(Base *b) {
        Derived *d = static_cast<Derived *>(b);
        std::cout << "x = " << d->x << ", y = " << d->y << "\n";
    }

    Derived() {
        vptr = &DERIVED_VTABLE;
    }
};
const BaseVtable Derived::DERIVED_VTABLE{Derived::print_impl};

int main() {
    Base b;     // vptr == &BASE_VTABLE, x
    Derived d;  // vptr == &DERIVED_VTABLE, x, y
    b.print();
    d.print();

    Base &db = d;
    db.print();

    std::cout << sizeof(Base) << ", " << sizeof(Derived) << "\n";

    [[maybe_unused]] std::vector<Derived> vec(1'000'000);
}
