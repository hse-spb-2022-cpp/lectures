#include <iostream>
#include <memory>
#include <thread>

int main() {
    std::shared_ptr<int> p = std::make_unique<int>(10);

    // Each shared_ptr<int> p is actually three objects with different semantics:
    // 1. `p` itself is not thread-safe, but you can a) read-only; b) use mutex; or c) use std::atomic_* functions.
    // 2. Reference counter inside `p` is thread-safe (probably via atomic)
    // 3. `*p` is not thread-safe, but you can use mutex

    std::thread t1([p]() {
        for (int i = 0; i < 100'000; i++) {
            auto p2 = p;  // Thread-safe, even though it increases reference counter.
            ++*p;  // Non thread-safe.
        }
    });

    std::thread t2([p]() {
        for (int i = 0; i < 100'000; i++) {
            auto p2 = p;
            ++*p;
        }
    });

    t1.join();
    t2.join();

    std::cout << *p << std::endl;  // race-y.
    std::cout << p.use_count() << std::endl;  // non-race-y, always 1 here.
    p = nullptr;  // No leaks.
}
