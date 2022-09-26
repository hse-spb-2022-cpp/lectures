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

    // left-hand side, right-hand side
    friend bool operator==(const bigint &lhs, const bigint &rhs) {
        return lhs.digits == rhs.digits;
    }
};

int main() {
    bigint a = 4, b = 5;
    std::cout << (a == b) << "\n";
    std::cout << (a == 6) << "\n";  // 6 is implicitly converted
    std::cout << (a == 4) << "\n";  // 4 is implicitly converted
    std::cout << (4 == b) << "\n";  // 4 is implicitly converted
}
