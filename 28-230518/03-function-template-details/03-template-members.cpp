#include <iostream>

template<typename T, int Value>
struct Foo {
    Foo() {}

    Foo(const Foo<T, Value> &) {
        std::cout << "copy constructor" << std::endl;
    }

    template<int Value2>
    Foo(const Foo<T, Value2> &) {
        std::cout << Value2 << " --> " << Value << std::endl;
    }

    template<typename W>
    void foo(const W &) {
    }

    template<typename U, typename W>
    void bar(const W &) {
    }

    template<typename T2, int Value2>
    bool operator==(const Foo<T2, Value2> &) {
        return true;
    }
};

int main() {
    [[maybe_unused]] Foo<int, 10> x;
    [[maybe_unused]] Foo<int, 11> y;
    [[maybe_unused]] Foo<char, 11> z;

    // Cannot specify explicit template arguments for constructors.
    [[maybe_unused]] Foo<int, 10> x1 = x;
    [[maybe_unused]] Foo<int, 10> x1b(x);
    [[maybe_unused]] Foo<int, 10> x2 = y;
    [[maybe_unused]] Foo<int, 10> x2b(y);
    // [[maybe_unused]] Foo<int, 10> x3 = z;

    x.foo(z);  // argument deduction works
    x.foo<>(z);  // argument deduction works
    x.bar<int>(z);  // partial argument deduction works

    x == y;  // Oops: Foo<int, 10> == Foo<int, 11>
    x == z;  // Oops: Foo<int, 10> == Foo<char, 11>
}
