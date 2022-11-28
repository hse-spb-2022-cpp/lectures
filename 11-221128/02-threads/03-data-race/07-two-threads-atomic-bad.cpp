#include <atomic>
#include <iostream>
#include <thread>

#pragma GCC optimize ("O0")

const int N = 50'000'000;
const int M = 10'000;

int main() {
    std::atomic<int> data = 0;
    auto worker = [&]() {
        for (int i = 0; i < N; i++) {
            data = data + 1;
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
