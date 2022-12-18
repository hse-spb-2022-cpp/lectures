#include <thread>
#include <iostream>
#include <deque>

int main() {
    std::deque<int> q;

    std::thread t1([&]() {
        for (int i = 0; i < 1'000'000; i++) {
            q.push_back(i);
        }
    });
    std::thread t2([&]() {
        while (!q.empty()) {
            std::cout << q.front() << "\n";
            q.pop_front();
        }
    });
    t1.join();
    t2.join();
}
