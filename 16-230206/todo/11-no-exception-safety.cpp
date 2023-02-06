#include <iostream>
#include <vector>

struct Data {
    std::vector<int> a, b;
};

int main() {
    Data x, y;
    // .....
    x = y;  // x.a = x.b; y.a = y.b;
    // Oops: not exception safe
}
