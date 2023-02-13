#include <chrono>
#include <iostream>

// Conclusion: exceptions are for exceptional cases only! Sad path is much, much slower.

bool foobar(int a, int b, bool please_throw) {
//    if (please_throw) {
        if (a % b) {
            //throw 0;  // todo: commenting out makes program faster
            return false;
        }
        return true;
//    }
    return a % b == 0;
}

const int STEPS = 100'000'000; // Note: much fewer steps.

int main() {
    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < STEPS; i++) {
//        try {
            foobar(12, 3, true);
//        } catch (...) {
//        }
    }

    auto duration = std::chrono::steady_clock::now() - start;
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << "ms\n";
}
