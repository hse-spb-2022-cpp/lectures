#include <iostream>
#include <string>

int main() {
    std::string s = std::to_string(10);
    // std::string s2 = static_cast<std::string>(10);  // compilation error
    std::cout << s.size() << ' ' << s << "\n";

    int x = std::stoi("123");  // string-to-int, stoll
    std::cout << x << "\n";

    std::string s3 = static_cast<std::string>(0);  // UB, because C++ and legacy
    std::cout << s3 << '\n';

    std::cout << "oops\n";
}
