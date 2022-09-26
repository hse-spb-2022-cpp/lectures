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

    bigint &operator++() {  // returns the new value, this object
        return *this;
    }

    bigint operator++(int) {  // returns old value, should be a copy
    }
};

int main() {
    bigint a = 4;
    ++a;  // a.operator++()
    a++;  // a.operator++(0)
}
