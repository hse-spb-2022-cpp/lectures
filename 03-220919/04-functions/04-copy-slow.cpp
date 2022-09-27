#include <cassert>
#include <iostream>
#include <string>

int sz(std::string s) {  // pass-by-value
    return static_cast<int>(s.size());
}

int main() {
    const int LEN = 1'000'000;

    std::string s(LEN, 'x');
    std::cout << s.size() << '\n';

    for (int i = 0; i < 1'000'000; i++) {
        assert(s.size() == LEN);
    }
    std::cout << "OK 1/2\n";

    for (int i = 0; i < 1'000'000; i++) {
        assert(sz(s) == LEN);
    }
    std::cout << "OK 2/2\n";
}
