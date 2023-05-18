#include <array>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

// For both class and function templates:

// You may want a template of a specific 'kind' as a paremeter. Works with argument deduction as well.
// Since C++17: works even though std::vector<T, Alloc>, see https://wg21.link/p0522r0
//              Clang disables it by default because it is 'incomplete': https://github.com/llvm/llvm-project/issues/42305
template<typename T, template<typename> typename Container = std::vector>
struct treap {
    Container<std::pair<T, int>> data;  // (value, priority)
};

template<typename T, template<typename, typename> typename Container = std::vector>
struct foo {};

template<typename T, template<typename, int> typename Container = std::array>
struct bar {};

// Compare this with easier to write and read:
template<typename T, typename Container = std::vector<T>>
struct priority_queue {
    Container c;
    // Cannot create Container<std::pair<T, int>>
};

int main() {
    treap<std::string> h1;
    h1.data.emplace_back("hello", 20);

    treap<std::string, std::set> h2;  // Does not make much sense, but compiles.
    h2.data.emplace("hello", 20);

    // treap<int, std::map> h3;
}
