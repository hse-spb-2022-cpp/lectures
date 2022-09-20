#include <iostream>
#include <vector>

int main() {
    std::vector v{1, 2, 3};
#if 1
    // FIXME: infinite loop and UB
    std::cout << "===== loop 1 =====\n";
    for (auto i = v.size() - 1; i >= 0; i--) {
        std::cout << v[i] << "\n";
    }
#endif

#if 1
    std::cout << "===== loop 2 =====\n";
    // FIXME: sometimes UB
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

#if 1
    std::cout << "===== loop 4 =====\n";
    // Good, but weird
    for (auto i = v.size(); i-- > 0;) {
        std::cout << v[i] << "\n";
    }
#endif

#if 1
    std::cout << "===== loop 5 =====\n";
    // for (int i = v.size() - 1; i >= 0; i--) {  // UB if v.empty()
    // Good, but weird
    for (int i = static_cast<int>(v.size()) - 1; i >= 0; i--) {
        std::cout << v[i] << "\n";
    }
#endif
}
