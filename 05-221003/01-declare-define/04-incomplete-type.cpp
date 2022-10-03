#include <iostream>
#include <vector>

// https://en.cppreference.com/w/cpp/language/type
struct Bar;  // forward declaration

struct Foo {
    // Bar b;  // compilation error: incomplete type
    std::vector<Bar> bs;

    void doit() {
        bs.push_back(Bar());
        Bar b2;
        bs[0].bar_do();
    }
    friend void foo_friend() {
        Bar b3;
    }
};

struct Bar {
    Foo f;
};

int main() {
}
