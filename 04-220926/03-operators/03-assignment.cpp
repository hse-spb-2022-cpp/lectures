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

    bigint &operator+=(const bigint &other) {
        digits[0] += other.digits[0];
        return *this;  // should return reference to 'this' object,
                       // `*this` is magic at the moment.
    }

    operator int() const {
        return digits[0];
    }
};

int main() {
    bigint a = 4, b = 5;
    std::cout << (a += a += b) << "\n";  // a += b -> 9; 9 += 9 -> 18
    (b += 1) += 1;
    std::cout << b << "\n";  // b += 1, b += 1 --> 7
}
