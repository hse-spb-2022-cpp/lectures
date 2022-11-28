#include <cstdlib>
#include <iostream>
#include <mutex>
#include <thread>
#include <string>

void writeln(const std::string &s) {
    std::mutex m;
    m.lock();
    for (std::size_t i = 0; i < s.size(); i++) {
        std::cout << s[i];
    }
    std::cout << '\n';
    m.unlock();
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
