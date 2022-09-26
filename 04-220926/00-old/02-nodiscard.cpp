#include <cassert>
#include <iostream>
#include <tuple>

[[nodiscard]] int sum(int a, int b) {
    return a + b;
}

int readInt() {
    int x;
    std::cin >> x;
    assert(std::cin);
    return x;
}

int main() {
    std::cout << sum(2, 3) << "\n";  // makes sense
    sum(5, 6);  // totally useless, we want a warning from the compiler

    readInt();  // skip the number. Kind of useless, [[nodiscard]] is a matter of taste
    std::ignore = readInt();  // explicit ignore
    sum(readInt(), readInt());  // totally useless, just readInt(), readInt()
}
