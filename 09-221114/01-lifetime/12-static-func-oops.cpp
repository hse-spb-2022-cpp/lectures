#include <cassert>
#include <iostream>
#include <vector>

void foo(bool condition, int n) {
    if (condition) {
        std::cout << "inside if\n";
        static std::vector<int> v(n);
        //static std::vector<int> v((std::cout << "inited\n", n));

        /*static std::vector<int> v;
        v.clear();
        v.resize(n);*/

        // OR: v.assign(n);
        std::cout << v[0] << " " << v.size() << "\n";
        assert(static_cast<int>(v.size()) == n);
        v[0] = 123;
    }
}

int main() {
    foo(false, 9);
    foo(true, 10);
    foo(true, 11);
}
