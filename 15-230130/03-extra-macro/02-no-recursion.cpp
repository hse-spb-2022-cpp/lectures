#include <iostream>

#define FOO(x) if (x > 0) { std::cout << x; FOO(x - 1) }

// Extra reading: Boost::PP (preprocessor).

int main() {
    FOO(5);
}
