#include <iostream>
#include <vector>
#include <set>

// class template
template<typename/* class */ C>  // C++20: concepts
struct templ_foo {
    typename C::iterator value;  // checked on class template instantiation
    // std::vector<int>::iterator

    // methods are checked on method instantiation only
    static void static_method() {
        C::foobarbaz();
    }

    void foo(C &c) {
        c.push_back(10);
    }

    void wtf() {
        C::hregfiuhtrghtiughgihtrg(10, 'h', "hello");
    }
};

int main() {
    {
        [[maybe_unused]] templ_foo<std::vector<int>> x;
        std::vector<int> v;
        x.value = v.begin();
        x.foo(v);

        // templ_foo<std::vector<int>>::static_method();
    }

    {
        [[maybe_unused]] templ_foo<std::set<int>> x;
        std::set<int> s;
        x.value = s.begin();
//        x.foo(s);
    }
//    [[maybe_unused]] templ_foo<int> y;
}
