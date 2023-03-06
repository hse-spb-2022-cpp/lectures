#include <iostream>
#include <mutex>
#include <thread>

struct Foo {
private:
    std::mutex m;

public:
    void foo(int x) {  // Атомарная операция, atomic.
        std::unique_lock l(m);
        std::cout << "foo(" << x << ")\n";
    }

    void double_foo(int x) {  // Неатомарная операция :(
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
    for (int i = 0; i < N; i += 10)
        f.double_foo(N + i);
    t.join();
}
