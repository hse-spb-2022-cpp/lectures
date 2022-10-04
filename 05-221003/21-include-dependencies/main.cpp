#include "foo.hpp"

int main() {
    get_foo().method();

    Foo f = get_foo();
    f.method();

    Foo f2;
    f2.method();
}
