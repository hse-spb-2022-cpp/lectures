#include <cassert>
#include <iostream>
#include <string>
#include <vector>

struct A { int val = 0; };
struct B { int val = 0; };
struct C { int val = 0; };
struct D { int val = 0; };

template<typename T>
auto println(const T &v) -> decltype(std::cout << v.val, void()) {
    std::cout << v.val << "\n";
}

struct E { int val2 = 0; };
struct F { int val2 = 0; };

template<typename T>
decltype(std::cout << std::declval<T>().val2, void()) println(const T &v) {
    std::cout << v.val2 << "\n";
}

int main() {
    A a{10};
    println(a);  // 10

    std::string s = "hello";
    // println(s);  // standard error message

    [[maybe_unused]] E e{40};
    println(e);
}
