#include <iostream>
#include <vector>

std::vector<int>& foo() {
    std::vector<int> vec{1, 2, 3};
    return vec;
}

int main() {
    std::vector<int> &vec1 = foo();  // Not UB
    std::cout << vec1.size() << "\n";  // UB

    std::vector<int> vec2 = foo();  // UB, because copy constructor
    std::cout << vec2.size() << "\n";  // UB
}
