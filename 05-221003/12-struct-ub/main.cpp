#include <vector>

struct Foo {
    // Different order of fields: UB.
    std::vector<int> v;
    int a = 10;

    void method();
};

Foo get_foo();

int main() {
    // get_foo() creates vector in one place; but destruction thinks it's in the other place.
    get_foo().method();

    Foo f = get_foo();
    f.method();
}
