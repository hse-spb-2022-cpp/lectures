#include <iostream>

int main() {
    {
        int wtf = 123;
        std::cout << wtf << "\n";
    }
    {
        int x;
        x = x * 0;  // reading from uninitialized variable is UB (undefined behavior): https://notes.algoprog.ru/cpp/additional.html#undefined-behavior
        std::cout << x << "\n";  // but it behaves ok with my compiler in this program
        // Note: if not multiplied by `0`, it's constant on my Windows and something random on my Linux.
    }
}
