#include <iostream>
#include <map>

struct Foo {
private:
    int x = 0;

    void foo() {
        x++;
    }

public:
    struct Bar {  // has access to all privates of Foo
        int y = 0;
        void foo() {
            // x++;
            Foo f;
            f.x++;
            f.foo();
            y++;
        }
    };

private:
    struct Baz {};
};

int main() {
    std::map<int, int>::iterator it;
    Foo::Bar b;
    b.foo();

    Foo::Baz z;
}
