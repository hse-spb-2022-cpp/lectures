#include <iostream>
#include <type_traits>

template<typename T>
struct MyClass {
#if 0
    // Checking signature on class instantiation fails. No SFINAE: not a template
    std::enable_if_t<std::is_same_v<T, int>, int> foo_bad_1() {
        return 1;
    }
    int foo_bad_1() const {
        return 2;
    }
#endif

#if 0
    // Checking signature on class instantiation fails. No SFINAE: the error does not depend on template parameter
    template<typename = void>
    std::enable_if_t<std::is_same_v<T, int>, int> foo_bad_2() {
        return 1;
    }
    int foo_bad_2() const {
        return 2;
    }
#endif

    template<typename U = T>  // OK
    std::enable_if_t<std::is_same_v<U, int>, int> foo() {
        static_assert(std::is_same_v<T, int>);
        return 10;
    }
    int foo() const {
        return 20;
    }
};

int main() {
    {
        MyClass<int> a;
        std::cout << a.foo() << "\n";  // 10

        const auto &b = a;
        std::cout << b.foo() << "\n";  // 20
    }
    {
        MyClass<double> a;
        std::cout << a.foo() << "\n";  // 20

        const auto &b = a;
        std::cout << b.foo() << "\n";  // 20
    }
}
