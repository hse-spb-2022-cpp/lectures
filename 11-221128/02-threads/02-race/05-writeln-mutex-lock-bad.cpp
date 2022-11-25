#include <cstddef>
#include <iostream>
#include <mutex>
#include <thread>
#include <string>

std::mutex m;
void writeln(const std::string &s) {
    std::unique_lock{m};
    for (std::size_t i = 0; i < s.size(); i++) {
        std::cout << s[i];
    }
    std::cout << '\n';
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
