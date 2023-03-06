#include <iostream>
#include <mutex>
#include <thread>

struct User {
private:
    mutable std::mutex m_;
    int balance_ = 1'000'000;

public:
    // TOC-TOU is imminent! Just by looking at the API.
    int balance() const {
        std::unique_lock l(m_);
        return balance_;
    }

    void decrease_balance(int decrease_by) {
        std::unique_lock l(m_);
        balance_ -= decrease_by;
    }
};

int main() {
    User u;
    std::thread t([&u]() {
        while (u.balance() >= 3) {  // time of check
            u.decrease_balance(3);  // time of use
        }
    });
    while (u.balance() >= 4) {  // time of check
        u.decrease_balance(4);  // time of use
    }
    t.join();
    std::cout << u.balance() << "\n";  // Should be >= 0
}
