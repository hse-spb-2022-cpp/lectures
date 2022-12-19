#include <iostream>
#include <string>

int main() {
    std::string x = "a", y = "a", z = "z";
    if (x == y == z) {
        std::cout << "wtf\n";
    }
}
