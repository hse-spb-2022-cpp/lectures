#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec1('a', 'b');  // vec2(97, 98);
    std::cout << vec1.size() << ' ' << vec1[0] << '\n';

    std::vector<int> vec2{'a', 'b'};
    std::cout << vec2.size() << ' ' << vec2[0] << '\n';  // 2 elements: 97, 98.
}
