#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int v1[3], v2[3];  // uninitialized memory
    // no push_back, pop_back, resize
    v2 = v1;  // compilation error

    [[maybe_unused]] int v3[n];  // non-standard extension: variable-length-array (VLA)

    // Do not use!
}
