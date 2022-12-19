#include <iostream>

struct Foo {
private:
    int x = 10;

    friend void print(const Foo &f);
};

void print(const Foo &f) {
    std::cout << f.x << "\n";
}

int main() {
    Foo f;
    print(f);
}
