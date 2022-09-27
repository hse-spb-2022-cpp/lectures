#include <iostream>

void print(int a) {
    std::cout << a << '\n';
    if (a == 5) {
        return;
    }
    std::cout << "a is not 5\n";
    return;  // optional
}

int main() {
    print(5);
    print(6);
}
