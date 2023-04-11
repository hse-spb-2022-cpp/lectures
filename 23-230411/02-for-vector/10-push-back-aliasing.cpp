#include <iostream>
#include <vector>

void push_back_good(std::vector<int> &v, const int &x) {
    v.push_back(x);
}

void push_back_bad(std::vector<int> &v, const int &x) {
    v.reserve(v.size() + 1);
    // Do not have to reallocate now!
    v.push_back(x);
}

int main() {
    {
        std::vector<int> v{1, 2, 3, 4};
        push_back_good(v, v[0]);
        std::cout << v[4] << "\n";
    }
    {
        std::vector<int> v{1, 2, 3, 4};
        push_back_bad(v, v[0]);  // UB
        std::cout << v[4] << "\n";
    }
}
