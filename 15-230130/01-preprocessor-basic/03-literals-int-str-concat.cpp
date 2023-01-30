#include <iostream>
#include <string>

int main() {
    [[maybe_unused]] int x = 0x12;

    int y = 1\
234;
    std::cout << y << "\n";

    std::string s1 = "hello" "wor\
ld";
    [[maybe_unused]] std::string s2 = "he\n\t\xFF" R"foo(Hello World)foo";
    std::cout << s1 << "\n";
}
