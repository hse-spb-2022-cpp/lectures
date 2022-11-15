#include <iostream>
#include <vector>
#include <memory>

struct Foo {
    std::vector<int> v;

    Foo() : v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10} {}
};

int main() {
    {
        Foo *b = nullptr;
        {
            Foo *f = new Foo;

            b = f;
            std::cout << f->v[4] << "\n";
            std::cout << b->v[4] << "\n";

            delete f;
        }
        delete b;  // double free
    }
    {
        std::unique_ptr<Foo> b;
        {
            auto f = std::make_unique<Foo>();

            b = f;  // copy is prohibited.
            // b = std::unique_ptr<Foo>(f.get());  // copy, but will do double free

            std::cout << f->v[4] << "\n";
        }
        std::cout << b->v[4] << "\n";
    }
}
