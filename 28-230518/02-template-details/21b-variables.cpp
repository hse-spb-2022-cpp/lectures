#include <iostream>
#include <string>

// Since C++17
template<typename T>
T var{};

int main() {
    var<int> = 10;  // `var<int>` is a name
    var<std::string> = "hello";

    std::cout << var<int> << "\n";
    std::cout << var<std::string> << "\n";
}
