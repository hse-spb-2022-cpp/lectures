#include <iostream>
#include <vector>

int main() {
    std::vector v{1, 2, 3};
    // FIXME: infinite loop
    // Either signed + static_cast, or `i - 1`.
    for (auto i = v.size() - 1; i >= 0; i--) {
        std::cout << i << "\n";
    }
}
