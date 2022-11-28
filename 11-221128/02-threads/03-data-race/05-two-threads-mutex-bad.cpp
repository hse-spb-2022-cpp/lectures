#include <iostream>
#include <mutex>
#include <thread>

#pragma GCC optimize ("O0")

const int N = 5'000'000;
const int M = 10'000;

int main() {
    std::mutex m;
    int data = 0;
    auto worker = [&]() {
        for (int i = 0; i < N; i++) {
            std::unique_lock l{m};
            data++;
        }
    };
    std::thread t1(worker);
    std::thread t2(worker);
    for (int i = 0; i < M; i++) {
        int data_snapshot = data;
        // todo: example: copy vector
        if (data_snapshot % 2 == 0) {
            std::cout << "data is " << data_snapshot << " (in progress)\n";
        }
    }
    t2.join();
    t1.join();
    std::cout << "data is " << data << "\n";
    return 0;
}
