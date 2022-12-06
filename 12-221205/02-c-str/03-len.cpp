#include <algorithm>
#include <cstring>
#include <cstddef>
#include <iterator>
#include <iostream>

int botva[10];

bool has_a(const char *str) {
//    for (std::size_t i = 0; i < std::strlen(str); i++) {
//    for (std::size_t i = 0, len = std::strlen(str); i < len; i++) {
    for (std::size_t i = 0; str[i]; i++) {
        if (str[i] == 'a') {
            return true;
        }
        botva[0] = 123;
    }
    return false;
}

int main() {
    {
        const char *a = "hello";
        int len = 0;
        while (a[len]) {
            len++;
        }
        std::cout << len << "\n";
        std::cout << std::strlen(a) << "\n";
    }
    {
        static char str[100'000'000];
        std::fill(std::begin(str), std::end(str) - 1, 'x');
        *(std::end(str) - 1) = 0;  // '\0'

        std::cout << std::strlen(str) << "\n";
        std::cout << has_a(str) << "\n";
    }
}
