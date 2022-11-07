#include <cassert>
#include <iostream>
#include <memory>
#include <vector>

struct Foo {
    std::vector<int> v;

    Foo() : v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10} {}
};

Foo *bad() {
    std::unique_ptr<Foo> f = std::make_unique<Foo>();
    Foo *ptr = f.get();
    assert(ptr->v[3] == 4);
    return ptr;
}

int main() {
    Foo *f = bad();
    *f;  // UB, because unique_ptr `delete`d the object
    std::cout << f->v[3] << "\n";
}
