#include <cassert>
#include <iostream>
#include <vector>
#include <sstream>

struct bigint {
private:
    std::vector<int> digits;

public:
    bigint() {}
    bigint(int digit) : digits{digit} {
        assert(0 <= digit && digit < 10);
    }

    friend std::istream &operator>>(std::istream &is, bigint &b) {
        is >> b.digits[0];
        // Less naive, not required in lab: https://en.cppreference.com/w/cpp/named_req/FormattedInputFunction
        return is;
    }
};

int main() {
    bigint a = 4;
    std::cout << a << "\n";
    (std::cout << a) << "\n";

    std::stringstream s;
    s << a << "\n";
    std::cout << s.str();
}
