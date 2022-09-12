#include <iostream>
#include <vector>

int main() {
    std::vector<int> v{1, 2, 3};
    std::cout << v[-1] << "\n";  // UB, not v[2], unlike Python
}
