#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

// For both class and function templates:

// 'class' == 'typename' in the line below. 'struct' is not allowed.
template<typename C = int, typename = char, typename = double, int /*Val*/ = 10>
struct templ_foo {
};
templ_foo<std::vector<int>, char, bool> x;
templ_foo<std::vector<int>> y;
templ_foo<> z;
templ_foo zz;  // Available because of CTAD (C++17), otherwise 'templ_foo' is a template, not a class
// vector v{1, 2, 3};  // CTAD as well

int main() {
}
