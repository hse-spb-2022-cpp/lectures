#include <thread>
#include <iostream>
#include <deque>
#include <mutex>

int main() {
    std::mutex m;
    std::deque<int> q;

    std::thread t1([&]() {
        for (int i = 0; i < 1'000'000; i++) {
            std::unique_lock l(m);
            q.push_back(i);
        }
    });
    std::thread t2([&]() {
        while (true) {
            std::unique_lock l(m);
            if (q.empty()) {
                break;
            }
            std::cout << q.front() << "\n";
            q.pop_front();
        }
    });
    t1.join();
    t2.join();
}
