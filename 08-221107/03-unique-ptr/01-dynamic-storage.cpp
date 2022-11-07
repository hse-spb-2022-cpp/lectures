#include <vector>

struct Foo {
    std::vector<int> vec;
    Foo() : vec(10) {}
};

Foo *create_foo() {
    Foo *f = new Foo;  // Dynamic storage duration for 'Foo'.
                       // "На куче" (heap)
    f->vec.resize(20);
    return f;
}

int main() {
    Foo *f = create_foo();
    Foo &fref = *f;
    fref.vec.resize(30);

    delete f;  // Leak otherwise
    // delete f;  // Double-free
    f = nullptr;
    delete f;  // ok

    /*{
        Foo f_automatic;
        Foo *f_automatic_ptr = &f_automatic;
        delete f_automatic_ptr;  // UB
    }*/
}
