#include <iostream>
#include <vector>

struct Bar {
    std::vector<int> v;
    Bar() : v(10) {
        std::cout << "Bar()\n";
    }
};

[[maybe_unused]] int global_x;  // Static storage duration. not default-initialized (reading is UB),
                                //                          but value-initialiezd (0).
[[maybe_unused]] Bar global_b;  // Static storage duration.

int main() {
    int x = 10;  // Automatic, "на стэке".
    static int y = 20;  // Static, "в глобальной памяти".
    std::cout << x << " " << y << "\n";

    {
        static int data[1'000'000];
        // static int data[1'000'000] = {1, 2, 3};
        std::vector<int> v(10);
        std::cout << data[0] << "\n";
    }

    // data[10] = 123;
}
