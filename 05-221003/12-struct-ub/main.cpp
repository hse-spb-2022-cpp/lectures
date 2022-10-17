#include <iostream>
#include <vector>

struct Foo {
    // Different order of fields: UB.
    std::vector<int> v;
    int a = 10;

    void method();
};

Foo get_foo();

int main() {
    {
        Foo f;
        f.v.push_back(123);
        f.method();
    }

    std::cout << "point 1\n";

    // get_foo() creates vector in one place; but destruction thinks it's in the other place.
    get_foo().method();

    std::cout << "point 2\n";

    Foo f = get_foo();
    f.method();
    std::cout << f.a << " " << f.v.size() << "\n";
}
