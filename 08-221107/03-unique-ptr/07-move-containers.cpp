#include <iostream>
#include <string>

int main() {
    std::string s = "hi";
    std::string s2 = std::move(s);
    // `s` is not guaranteed to be empty
    std::cout << "|" << s << "| |" << s2 << "|\n";
}
