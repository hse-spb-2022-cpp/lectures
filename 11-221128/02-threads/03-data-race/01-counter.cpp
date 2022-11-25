#include <iostream>
#include <thread>

#pragma GCC optimize ("O0")

const int N = 500'000'000;
const int M = 1000;

int main() {
    int data = 0;
    auto worker = [&]() {
        for (int i = 0; i < N; i++) {
            data++;
        }
    };
    std::thread t(worker);
    for (int i = 0; i < M; i++) {
        std::cout << "data is " << data << " (in progress)\n";
    }
    t.join();
    std::cout << "data is " << data << "\n";
    return 0;
}
