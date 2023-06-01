#include <iostream>

int main() {
    // Since C++14
    auto print1 = [](auto x, auto y) {  // Independent implicit template parameter for each argument.
        std::cout << x << " " << y << "\n";
    };
    print1(10, 20.0);
    print1(10, "hello");

    // Since C++20: https://stackoverflow.com/a/54126333/767632
    auto print2 = []<typename T>(const T &x, const T &y) {
        std::cout << x << " " << y << "\n";
    };
    print2(10, 20);
    // print2(10, 20.0);
}
