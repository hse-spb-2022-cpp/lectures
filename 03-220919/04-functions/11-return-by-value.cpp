#include <iostream>
#include <string>

std::string BIG(1'000'000, 'x');

std::string create_string() {
    return BIG;  // return copies; O(n)
}

int main() {
    for (int i = 0; i < 1'000'000; i++) {
        create_string();
    }
    std::cout << "OK\n";
}
