#include <array>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

// For both class and function templates:

// Types/default values of following parameters may depend on prior.
// Unlike functions: `void foo(int a, int b = a)` is invalid.
template<typename C, C value, typename D = std::array<C, value>>
struct templ_bar {
};
templ_bar<int, 10> xx;  // templ_bar<int, int 10, array<int, 10>>
templ_bar<unsigned, 4'000'000'000> yy;  // templ_bar<unsigned, unsigned int 4000000000, array<unsigned, 4000000000>>

int main() {
}
