#include <iostream>

int sum(int a, int b) {
    a += b;
    if (a == 25) {
        return 10;
    }
}

int main() {
    int x = 5;
    std::cout << "Started\n";
    sum(x, 20);  // ok
    std::cout << "Middle\n";
    sum(x, 21);  // UB, caught by UBSan
    std::cout << "OK\n";
}
