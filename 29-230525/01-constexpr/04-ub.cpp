#include <vector>

int main() {
    // Since C++20: vector is constexpr
    static_assert([]() {
        std::vector<int> v;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        v.pop_back();
        // Compiler _should_ catch UB

        // v.pop_back();
        // v.pop_back();
        // v.pop_back();
        return v.size();
    }() == 2);
}
