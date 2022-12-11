#include <set>

int main() {
    auto l1 = [](int a, int b) { return a > b; };
    auto l2 = [](int a, int b) { return a > b; };
    std::set<int, decltype(l1)> s1(l1);
    // std::set<int, decltype(l1)> s2(l2);
}
