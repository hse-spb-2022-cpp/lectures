#include <cassert>
#include <iostream>
#include <vector>

struct bigint {
private:
    std::vector<int> digits;

public:
    bigint() {}
    bigint(int digit) : digits{digit} {
        assert(0 <= digit && digit < 10);
    }
    // Fun fact: this is wrong algorithmically. Guess how?

    bool operator==(const bigint &other) const {
        return digits == other.digits;
    }
};

int main() {
    bigint a = 4, b = 5;
    std::cout << (a == b) << "\n";
    std::cout << a.operator==(b) << "\n";
    std::cout << (a == 6) << "\n";  // 6 is implicitly converted
    std::cout << (a == 4) << "\n";  // 4 is implicitly converted
    std::cout << (4 == b) << "\n";  // does not convert 4 to bigint
}
