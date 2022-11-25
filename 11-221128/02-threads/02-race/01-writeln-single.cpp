#include <cstdlib>
#include <iostream>
#include <string>

void writeln(const std::string &s) {
    for (std::size_t i = 0; i < s.size(); i++) {
        std::cout << s[i];
    }
    std::cout << '\n';
}

int main() {
    for (;;) {
        writeln("Hello from the main thread");
    }
}
