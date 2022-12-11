#include <vector>
#include <iostream>

struct comma_separated_tag {};  // Not _t, it's reserved.
struct element_per_line_tag {};  // Not _t, it's reserved.

void println(const std::vector<int> &vec, comma_separated_tag) {
    bool first = true;
    for (const auto &item : vec) {
        if (!first) {
            std::cout << ", ";
        }
        first = false;
        std::cout << item;
    }
    std::cout << "\n";
}

void println(const std::vector<int> &vec, element_per_line_tag) {
    for (const auto &item : vec) {
        std::cout << item << "\n";
    }
}

int main() {
    std::vector<int> v{1, 2, 3};
    // type tags
    println(v, comma_separated_tag{});
    println(v, element_per_line_tag{});
}
