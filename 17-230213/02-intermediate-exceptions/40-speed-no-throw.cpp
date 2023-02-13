#include <chrono>
#include <iostream>

// There was no difference with/without noexcept with this example, but it may happen:
// 1. Say hello to no-noexcept-move and strong exception safety (will be later).
// 2. One can optimize code like `i++; my_noexcept(); i++;`
// 3. There is no need to prepare for stack unwind.
//
// -fno-exceptions did not make a difference for me as well.

bool foobar(int a, int b, bool please_throw) noexcept {
/*    if (please_throw) {
        if (a % b) {
            throw 0;
        }
        return true;
    }*/
    return a % b == 0;
}

const int STEPS = 100'000'000;

int main() {
    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < STEPS; i++) {
//        try {
          foobar(10, 3, false);
//        } catch (...) {
//        }
    }

    auto duration = std::chrono::steady_clock::now() - start;
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << "ms\n";
}
