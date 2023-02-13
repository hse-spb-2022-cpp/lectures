#include <iostream>

struct bigint {
    bigint(const std::string &s) {
        // TODO: ...
        std::cout << "constructing from string " << s << "\n";
    }
    bigint(int x) : bigint(std::to_string(x)) {  // Delegating constructor
        // bigint(std::to_string(x));  // bad attempt :(
        std::cout << "constructing from int " << x << "\n";
    }
    bigint() : bigint(0) {}
};

int main() {
    bigint x(123);
}
