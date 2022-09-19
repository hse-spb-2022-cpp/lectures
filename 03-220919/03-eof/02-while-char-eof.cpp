#include <iostream>

int main() {
    while (true) {
        char c = std::cin.get();
        if (c == std::char_traits<char>::eof()) {  // Some `char`'s values may coincide with `eof()`
            break;
        }
        std::cout << c << '\n';
    }
}
