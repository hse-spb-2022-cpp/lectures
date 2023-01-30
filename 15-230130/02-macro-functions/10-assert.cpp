#include <cassert>
#include <iostream>

void my_assert_1(bool expr) {
    if (!expr) {
        std::cout << "Assertion failed: ???????\n";
    };
}

#define my_assert_2(expr) \
    do { \
        if (!(expr)) { \
            std::cout << "Assertion failed: " #expr " at " __FILE__ ":" << __LINE__ << "\n"; \
        } \
    } while(0)

int main() {
    my_assert_1(2 * 2 == 5);
    my_assert_2(2 * 2 == 5);
    assert(2 * 2 == 5);
}
