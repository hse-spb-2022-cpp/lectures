#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    std::vector<int> v1(100000), v2;
    for (int i = 0; i < 100000; i++) {
        using std::swap;
        swap(v1, v2);
    }
    std::cout << v1.size() << "\n";
}
