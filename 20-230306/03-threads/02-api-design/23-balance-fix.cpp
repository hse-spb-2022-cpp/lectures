#include <cassert>
#include <iostream>
#include <mutex>
#include <thread>

struct User {
private:
    mutable std::mutex m_;
    int balance_ = 1'000'000;

public:
    // TOC-TOU is imminent! But the name suggests likewise.
    int approximate_balance() const {
        std::unique_lock l(m_);
        return balance_;
    }

    // No need to check before.
    bool decrease_balance(int decrease_by) {
        std::unique_lock l(m_);
        if (balance_ < decrease_by) {
            return false;
        }
        balance_ -= decrease_by;
        return true;
    }
};

int main() {
    User u;
    std::thread t([&u]() {
        while (u.decrease_balance(3))
            ;  // single operation
    });
    while (u.decrease_balance(4))
        ;  // single operation
    t.join();
    std::cout << u.approximate_balance() << "\n";
    assert(u.approximate_balance() >= 0);
}
