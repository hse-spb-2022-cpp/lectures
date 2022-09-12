#include <iostream>
#include <vector>

int main() {
    std::vector v{1, 2, 3};
#if 1
    // FIXME: infinite loop
    std::cout << "===== loop 1 =====\n";
    for (auto i = v.size() - 1; i >= 0; i--) {
        std::cout << v[i] << "\n";
    }
#endif

#if 1
    std::cout << "===== loop 2 =====\n";
    // FIXME: sometimes infinite loop and UB
    // Hint: empty
    for (auto i = v.size() - 1;; i--) {
        std::cout << v[i] << "\n";
        if (i == 0) {
            break;
        }
    }
#endif

#if 1
    std::cout << "===== loop 3 =====\n";
    // Good
    for (auto i = v.size(); i > 0; i--) {
        std::cout << v[i - 1] << "\n";
    }
#endif
}
