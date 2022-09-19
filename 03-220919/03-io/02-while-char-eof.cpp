#include <iostream>

int main() {
    while (true) {
        char c = std::cin.get();
        if (c == std::char_traits<char>::eof()) {  // theoretically can be not -1
            break;
        }
        std::cout << c << '\n';
    }
}
