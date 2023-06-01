#include <iostream>
#include <string>

// Since C++17: each value can have an independent type.
template<auto... Fs, typename... Args>
void executeAll(Args... args) {
    (Fs(args), ...);
}

void printInt(int x) { std::cout << x << "\n"; }
void printString(std::string s) { std::cout << s << "\n"; }

int main() {
    executeAll<printInt, printString>(10, "hello");
}
