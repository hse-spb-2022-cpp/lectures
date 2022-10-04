#include <vector>

struct Foo {
    int a = 10;
    std::vector<int> v;

    void method();
    void method_unused();
};

Foo get_foo();
