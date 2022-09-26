#include <iostream>

struct Foo {  // public:
    int x = 10;
};

class Bar {  // private:
// public:
    int x = 10;
};

// Different teams have different conventions.

int main() {
    Foo f;
    Bar b;
    std::cout << f.x << "\n";
    std::cout << b.x << "\n";
}
