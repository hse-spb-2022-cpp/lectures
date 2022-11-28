#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

std::vector<unsigned> results;

void worker(int begin, int end, int t) {
    unsigned sum = 0;
    for (int i = begin; i < end; i++) {
        sum += i * i / 2;
    }
    results[t] = sum;
}

int main() {
    const int N = 1'000'000'000;
    const int K = 3;

    auto start = std::chrono::steady_clock::now();

    std::vector<std::thread> ts;
    results.resize(K);
    for (int i = 0; i < K; i++) {
        std::thread t(worker, N * i / K, N * (i + 1) / K, i);
        ts.emplace_back(std::move(t));  // note: std::thread cannot be copied
    }
    for (auto &t : ts) {
        t.join();
    }

    unsigned result = 0;
    for (auto r : results) {
        result += r;
    }
    std::cout << result << "\n";
    std::cout << "Elapsed "
              << std::chrono::duration_cast<std::chrono::milliseconds>(
                     std::chrono::steady_clock::now() - start
                 )
                     .count()
              << "ms\n";
}
