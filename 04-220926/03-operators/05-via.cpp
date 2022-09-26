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

    bigint operator+(const bigint &other) const {
        return bigint(*this) += other;  // make a copy, alter it
    }
    
    bigint &operator+=(const bigint &other) {
        return *this = *this + other;
    }
};

bigint operator-(bigint lhs, const bigint &rhs) {
    return lhs -= rhs;  // lhs is a copy already
}

bigint &operator-=(bigint &lhs, const bigint &rhs) {
    return lhs = lhs - rhs;
}

int main() {
    bigint a = 4;
    bigint &b = a += 2;
    bigint c = 1;
    c += a += 2;
    c -= a -= 2;
}
