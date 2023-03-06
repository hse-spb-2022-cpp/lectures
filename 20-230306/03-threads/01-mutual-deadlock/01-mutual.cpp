#include <cassert>
#include <cstdlib>
#include <mutex>
#include <thread>

int main(int argc, char *argv[]) {
    assert(argc == 2);
    const int N = std::atoi(argv[1]);

    std::mutex m1, m2;
    std::thread t1([&]() {
        for (int i = 0; i < N; i++) {
            std::unique_lock a(m1);
            std::unique_lock b(m2);
        }
    });
    std::thread t2([&]() {
        for (int i = 0; i < N; i++) {
            std::unique_lock b(m2);
            std::unique_lock a(m1);
        }
    });
    // N=10'000: уже deadlock: пусть сначала каждый поток схватил себе m1/m2, а потом ждёт второй. А он занят.
    t2.join();
    t1.join();
}
