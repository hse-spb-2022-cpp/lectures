#include <iostream>
#include <vector>
#include <memory>

struct Foo {
    std::vector<int> v;

    Foo() : v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10} {}
};

int main() {
    {
        Foo *f = new Foo;
        Foo *b = nullptr;

        b = f;
        std::cout << f->v[4] << "\n";
        std::cout << b->v[4] << "\n";

        delete f;
        // delete b;  // double free
    }
    {
        auto f = std::make_unique<Foo>();
        std::unique_ptr<Foo> b;

        b = f;  // copy is prohibited.
        b = std::unique_ptr<Foo>(f.get());  // copy, but will do double free

        std::cout << f->v[4] << "\n";
        std::cout << b->v[4] << "\n";
    }
}
