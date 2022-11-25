#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>

void writeln(const std::string &s) {
    for (std::size_t i = 0; i < s.size(); i++) {
        std::cout << s[i];
    }
    std::cout << '\n';
    // std::cout << s << "\n";
}

int main() {
    std::thread t([]() {
        for (;;) {
            writeln("Hello from the second thread");
        }
    });
    for (;;) {
        writeln("Hello from the main thread");
    }
}
