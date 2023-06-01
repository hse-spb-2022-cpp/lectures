#include <cassert>
#include <functional>
#include <tuple>
#include <string>
#include <vector>

using std::string;
using std::vector;

void foo(int a, string b) {
    assert(a == 10);
    assert(b == "hello");
}

int main() {
    {
        std::tuple<int, vector<int>, string> t(10, vector<int>(2), "foo");
        auto t2 = std::make_tuple(10, vector<int>(2), "foo");  // t == t2
        assert(t == t2);
        int a = std::get<0>(t);  // 0 should be compile-time constant.
        string c = std::get<2>(t);
        assert(a == 10);
        assert(c == "foo");
    }

    {
        std::pair<int, string> p(10, "foo");
        std::tuple<int, string> t = p;  // Implicit conversion: pair --> tuple.
        auto tt = std::tuple_cat(t, t);  // Concatenation (cat)
        // You can get tuple element's type.
        std::tuple_element_t<0, decltype(tt)> x = std::get<0>(tt);
        static_assert(std::tuple_size_v<decltype(tt)> == 4);
        assert(x == 10);
    }

    {
        auto t = std::make_tuple(10, "hello");
        std::apply(foo, t);  // You can call a function
    }
}
