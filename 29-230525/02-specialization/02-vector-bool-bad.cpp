#include <iostream>
#include <vector>

// Specialize very carefully
// std::vector<bool> is a bad mistake: https://isocpp.org/blog/2012/11/on-vectorbool

template<typename V, typename F>
void for_each(V &v, F f) {
    for (auto &x : v) {  // Does not work with V=std::vector<bool>
        f(x);
    }
}

int main() {
    {
        std::vector<int> vec{1, 2, 3};
        for_each(vec, [](int &x) { x++; });
        std::cout << vec[0] << " " << vec[1] << " " << vec[2] << "\n";
    }
#if 1
    {
        std::vector<bool> vec{true, false, true};
        for_each(vec, [](bool &x) { x = !x; });
        std::cout << vec[0] << " " << vec[1] << " " << vec[2] << "\n";
    }
#endif
}
