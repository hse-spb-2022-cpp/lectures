#include <cstdio>
#include <utility>

int main() {
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            std::string temporary(10000, 'x');
            if (i * j == 24) {
                std::printf("%d %d\n", i, j);
                goto after_loop;  // No leaks!
            }
        }
    after_loop:;

    auto [a, b] = []() {
        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++) {
                if (i * j == 24) {
                    return std::make_pair(i, j);
                }
            }
    }();
    std::printf("%d %d\n", a, b);
}

/* Java:
outer_loop:
for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++) {
        if (...) {
            break outer_loop;
        }
    }
*/
