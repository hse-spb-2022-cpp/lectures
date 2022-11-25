#include <cstddef>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

std::mutex m;
void writeln(const std::string &s) {
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
            std::this_thread::yield();  // Костыль!
        }
    });
    for (;;) {
        writeln("Hello from the main thread");
        std::this_thread::yield();
    }
}
