#include <iostream>
#include <vector>

void may_throw(std::vector<int> &) {
    // maybe throw exception
}

int main() {
    try {
        // try {
        std::vector<int> v(100'000'000'000);
        // } catch
        v[99'999'999'999] = 123;
        may_throw(v);
    } catch (std::bad_alloc &) {
        std::cout << "caught bad_alloc inside v ctor or from may_throw\n";
    }
}
