#include <iostream>
#include <mutex>
#include <thread>

struct Foo {
private:
    std::mutex m;
    std::mutex m2;

public:
    void foo(int x) {  // Атомарная операция, atomic.
        std::unique_lock l(m);
        std::cout << "foo(" << x << ")\n";
    }

    void double_foo(int x) {  // Неатомарная операция :(
        std::unique_lock l(m2);  // Берём другой мьютекс, deadlock отсутствует.
        foo(x);
        foo(x + 1);
    }
};

int main() {
    const int N = 100'000;
    Foo f;
    std::thread t([&f]() {
        for (int i = 0; i < N; i += 10)
            f.double_foo(i);
    });
    // Теперь double_foo() между собой не пересекаются и foo() не пересекаются.
    // Но может влезть foo() внутри double_foo().
    for (int i = 0; i < N; i += 10)
        f.foo(N + i);
    t.join();
}
