#include <vector>

std::vector<int> foo() {
    return {1, 2, 3};  // implicit
    // return 1;  // implicit
    return std::vector{1, 2, 3};  // explicit
    return std::vector<int>(10);  // explicit
    return static_cast<std::vector<int>>(10);  // explicit
}

int main() {
}
