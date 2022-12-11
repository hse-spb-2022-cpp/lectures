#include <iostream>
#include <vector>

void println(int x) {
    std::cout << x << "\n";
}

void println(double x) {
    std::cout << x << "\n";
}

void println(const std::vector<int> &vec) {
    std::cout << "{";
    bool first = true;
    for (const auto &item : vec) {
        if (!first) {
            std::cout << ", ";
        }
        first = false;
        std::cout << item;
    }
    std::cout << "}\n";
}

int main() {
    println(10);
    println(1.2);
    println(std::vector{1, 2, 3});
//    println(123456789123456);
    println(1LL);
}
