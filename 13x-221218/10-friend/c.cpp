#include <iostream>

struct Foo;

namespace printers {
void print(const Foo &f);
}

struct Foo {
private:
    int x = 10;

    friend void printers::print(const Foo &f);
};

namespace printers {
void print(const Foo &f) {
    std::cout << f.x << "\n";
}
}

int main() {
    Foo f;
    printers::print(f);
}
