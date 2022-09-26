#include <iostream>

struct Foo {
private:
    int field = 10;

public:
    void increment() {
        field++;
    }

    
private:  // private, public, does not matter, visible to all
    friend bool eq(const Foo &a, const Foo &b) {
        return a.field == b.field;
    }
};

int main() {
    Foo f1, f2;
    f1.increment();
    std::cout << eq(f1, f2) << "\n";  // 0
    f2.increment();
    std::cout << eq(f1, f2) << "\n";  // 1
}
