#include <iostream>
#include <vector>

std::vector<int> vec;

int foo() {
    vec.push_back(20);
    return 123;
}

int main() {
    vec.push_back(10);
    vec[0] = foo();  // Safe since C++17: = computes rights first, left second.

    std::cout << vec.size() << "\n";
    std::cout << vec[0] << " " << vec[1] << "\n";
}
