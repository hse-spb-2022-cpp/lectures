#include <iostream>
#include <vector>

template<int X, bool SHOULD_THROW = false>
struct with_destructor {
    with_destructor(bool should_throw = false) {
        std::cout << "constructing " << X << " " << this << "\n";
        if (SHOULD_THROW || should_throw) {
            throw 0;
        }
        std::cout << "created " << this << "\n";
    }
    ~with_destructor() {
        std::cout << "destructing " << X << " " << this << "\n";
    }
};

int main() {
    try {
        with_destructor<1> arr[]{false, false, true, false};
    } catch (...) {
        std::cout << "Caught\n";
    }
    std::cout << "==========\n";
    try {
        std::vector<with_destructor<1>> vec{false, false, true, false};
    } catch (...) {
        std::cout << "Caught\n";
    }
}
