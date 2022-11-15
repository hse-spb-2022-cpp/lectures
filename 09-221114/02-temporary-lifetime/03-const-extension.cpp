#include <iostream>
#include <vector>

void println(const std::vector<int> &) {
}

int main() {
    // https://herbsutter.com/2008/01/01/gotw-88-a-candidate-for-the-most-important-const/
    const std::vector<int> &vec = std::vector{1, 2, 3};
    std::cout << vec.size() << "\n";

    println(std::vector{1, 2, 3});
}
