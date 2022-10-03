#include <iostream>

struct Foo {
    void foo() {
        bar();
    }

    void bar() {
        foo();
    }
};

int main() {
}
