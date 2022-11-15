#include <iostream>
#include <vector>

int main() {
    std::vector<int> v{10, 20};
    std::cout << sizeof(v) << "\n";

    /*struct vector<int> {
        int *buffer;
        size_t len;
        size_t capacity;
    };*/

    std::cout << &v << " " << &v[0] << " " << &v[1] << "\n";
    v.resize(100);
    std::cout << &v << " " << &v[0] << " " << &v[1] << "\n";
}
