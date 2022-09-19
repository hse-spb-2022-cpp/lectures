#include <iostream>

int main() {
    std::string s1;
    std::cin >> s1;  // skip whitespaces, read non-whitespaces
    std::cout << ">" << s1 << "<\n";

    std::string s2;
    std::getline(std::cin, s2);  // read until end of line
    std::cout << ">" << s2 << "<\n";
}
