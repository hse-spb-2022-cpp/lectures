#include <iostream>

struct Foo {
private:
    int x = 10;

    friend void print(const Foo &f) {
        std::cout << f.x << "\n";
    }
};
// void print(const Foo &f);

int main() {
    Foo f;
    print(f);
}
