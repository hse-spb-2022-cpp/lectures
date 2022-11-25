#include <iostream>
#include <mutex>
#include <thread>

#pragma GCC optimize ("O0")

const int N = 5000000;
const int M = 10000;

// Дополнительное чтение: у clang есть статический анализ: https://clang.llvm.org/docs/ThreadSafetyAnalysis.html
// Можно пометить int data GUARDED_BY(m); и он много чего проверит.

int main() {
    std::mutex m;
    int data = 0;
    auto worker = [&data, &m]() {
        for (int i = 0; i < N; i++) {
            std::unique_lock l{m};
            data++;
        }
    };
    std::thread t1(worker);
    std::thread t2(worker);
    for (int i = 0; i < M; i++) {
        std::unique_lock l(m);
        int data_snapshot = data;
        l.unlock();  // Не m.unlock()! Иначе unique_lock сделает unlock() ещё раз, это UB.

        if (data_snapshot % 2 == 0) {
            std::cout << "data is " << data_snapshot << " (in progress)\n";
        }
    }
    t2.join();
    t1.join();
    std::cout << "data is " << data << "\n";
    return 0;
}
