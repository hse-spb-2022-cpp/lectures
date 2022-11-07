#include <iostream>

struct Foo {
    int x = 20;

    void foo() {
        Foo *f = this;
        std::cout << x << "\n";
        std::cout << f->x << "\n";
        std::cout << this->x << "\n";
        std::cout << (*this).x << "\n";
    }
};

int main() {
    Foo{}.foo();
}
