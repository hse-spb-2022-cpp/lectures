#include <iostream>

int sum(int a, int b) {  // each parameter is a copy of an arguments; pass-by-value
    a += b;  // does not modifies arguments
    std::cout << "new a=" << a << "\n";
    return a;
}

int main() {
    int x = 5;
    std::cout << sum(x, 20) << '\n';  // 25
    std::cout << x << '\n';  // 5
    std::cout << sum(10, 20) << '\n';  // would be hard to modify 10
}
