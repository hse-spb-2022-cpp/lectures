#include <chrono>
#include <iostream>
#include <thread>

#pragma GCC optimize("-O2")

int main() {
    volatile int data = 0;
    volatile bool finished = false;

    std::thread t([&]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        // Hmm: compiler cannot reorder two writes below. But CPU still can!
        data = 123;
        finished = true;
    });

    while (!finished) {}
    // Hmm?
    std::cout << data << "\n";

    t.join();
}
