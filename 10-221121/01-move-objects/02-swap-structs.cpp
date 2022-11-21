#include <vector>
#include <iostream>
#include <algorithm>

struct S {
    std::vector<int> vec;
};

int main() {
    S v1, v2;
    v1.vec.resize(100000);
    for (int i = 0; i < 100000; i++) {
        using std::swap;
        swap(v1, v2);
    }
    std::cout << v1.vec.size() << "\n";
}

#if 0
// C++03
void swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

// C++11
void swap(T &a, &b) {
    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}
#endif
