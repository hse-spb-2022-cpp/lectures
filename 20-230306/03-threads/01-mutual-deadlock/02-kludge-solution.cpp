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
            std::scoped_lock a(m1, m2);
            // Под капотом вызывает std::lock.
            // Он пытается избежать deadlock, например:
            // while (true) {
            //     m1.lock();
            //     if (m2.try_lock()) break;
            //     m1.unlock();
            // }
            // 
            // Другой способ: программисту сделать глобальный порядок на mutex'ах.
            // Упражнение: доказать, что тогда deadlock'ов не будет.
            // При этом &m1 < &m2 — UB (нельзя сравнивать указатели не из одного массива/объекта), но можно через std::less<std::mutex*>
        }
    });
    std::thread t2([&]() {
        for (int i = 0; i < N; i++) {
            std::scoped_lock b(m2, m1);
        }
    });
    t2.join();
    t1.join();
}
