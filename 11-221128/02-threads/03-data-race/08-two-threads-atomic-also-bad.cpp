#include <atomic>
#include <iostream>
#include <thread>

#pragma GCC optimize ("O0")

const int N = 50000000;
const int M = 10000;

int main() {
    std::atomic<int> data = 0;
    auto worker = [&data]() {
        for (int i = 0; i < N; i++) {
            data++;
        }
    };
    std::thread t1(worker);
    std::thread t2(worker);
    for (int i = 0; i < M; i++) {
        if (data % 2 == 0) {
            std::cout << "data is " << data << " (in progress)\n";
        }
    }
    t2.join();
    t1.join();
    std::cout << "data is " << data << "\n";
    return 0;
}
