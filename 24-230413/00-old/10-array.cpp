#include <array>
#include <cassert>

int main() {
    // C arrays with C++ syntax, more consistent, strictly better
    [[maybe_unused]] std::array<int, 5> a1;  // default-initialized;
    [[maybe_unused]] std::array<int, 5> a2 = {1, 2, 3};  // 1, 2, 3, 0, 0
    assert(a2.size() == 5);  // Has some methods

    [[maybe_unused]] std::array<int, 5> a3 = a2;  // can copy

    std::array<int, 0> a4;  // Can be empty
    assert(a4.begin() == a4.end());
    assert(a4.empty());

    [[maybe_unused]] auto [a, b, c, d, e] = a3;  // structured binding also works.
}
