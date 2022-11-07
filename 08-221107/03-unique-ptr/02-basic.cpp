#include <iostream>
#include <vector>
#include <memory>

struct Foo {
    std::vector<int> v;

    Foo() : v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10} {}
};

int main() {
    {
        // raw pointer / чистый указатель
        Foo *f = new Foo;
        std::cout << f->v[4] << "\n";
        delete f;
    }
    {
        // smart pointer / умный указатель
        std::unique_ptr<Foo> f;
        std::cout << (f == nullptr) << "\n";

        f = std::unique_ptr<Foo>(new Foo());
        // f = std::make_unique<Foo>();  // C++14
        std::cout << f->v[4] << "\n";
    }
}
