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

    // std::ostream& is generalization of std::stringstream and std::cout,
    // see 'inheritance' later.
    friend std::ostream &operator<<(std::ostream &os, const bigint &b) {
        os << b.digits[0];
        // Less naive, not required in lab: https://en.cppreference.com/w/cpp/named_req/FormattedOutputFunction
        return os;
    }
};

int main() {
    bigint a = 4;
    std::cout << a << "\n";
    (std::cout << a) << "\n";
    // (  std::cout.operator<<(a) ).operator<<("\n");
    // operator<<(  operator<<(std::cout, a)  , "\n");
    // operator<<(             std::cout      , "\n");

    std::stringstream s;
    s << a << "\n";
    std::cout << s.str();
}
