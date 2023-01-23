#include <iostream>
#include <vector>

// todo

// class template
template<typename/* class */ T, char some_value /* unused */>
struct templ_foo {
    T value1;
    bool value2;
};

int main() {
    [[maybe_unused]] templ_foo<int, 10> x;
    [[maybe_unused]] templ_foo<int, 10> y;
    [[maybe_unused]] templ_foo<int, 11> z;
    [[maybe_unused]] templ_foo<std::vector<int>, 10> botva;
    x = y;  // OK
    x = z;  // CE: different types

    std::cout << sizeof(x) << " " << sizeof(z) << " " << sizeof(botva) << "\n";

    struct Foo {};
    struct Bar {};
    Foo x1;
    Bar y1;
    x1 = y1;
}
