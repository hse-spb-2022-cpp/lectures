#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

// For both class and function templates:

// 'class' == 'typename' in the line below. 'struct' is not allowed.
template<typename C = int, typename = char, typename = double, int = 10>
struct templ_foo {
};
templ_foo<std::vector<int>, char, bool> x;
templ_foo<std::vector<int>> y;
templ_foo<> z;
templ_foo zz;  // Available because of CTAD, otherwise 'templ_foo' is a template, not a class

// Types/default values of following parameters may depend on prior.
// Unlike functions: `void foo(int a, int b = a)` is invalid.
template<typename C, C value, typename D = std::pair<C, C>>
struct templ_bar {
};
templ_bar<int, 10> xx;
templ_bar<unsigned, 4'000'000'000> yy;

// You may want a template of a specific 'kind' as a paremeter. Works with argument deduction as well.
// Since C++17: works even though std::vector<T, Alloc>, see https://wg21.link/p0522r0
//              Clang disables it by default because it is 'incomplete': https://github.com/llvm/llvm-project/issues/42305
template<typename T, template<typename> typename Container = std::vector>
struct heap {
    Container<std::pair<T, int>> data;  // (value, id)
};

// Compare this with easier to write and read:
template<typename T, typename Container = std::vector<T>>
struct priority_queue {
    Container c;
    // Cannot create Container<std::pair<T, int>>
};

int main() {
    heap<std::string> h1;
    h1.data.emplace_back("hello", 20);

    heap<std::string, std::set> h2;  // Does not make much sense, but compiles.
    h2.data.emplace("hello", 20);

    // heap<int, std::map> h3;
}
