#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    // Ternary operator.
    // Bad stuff happens when two branches are of different types.
    // (some complicate type deduction)
    return b ? gcd(b, a % b) : a;

    /* if (b != 0) {
        return gcd(....);
    } else { 
        return a;
    } */
}

// Since C++17: int std::lcm(int a, int b)
// https://codeforces.com/blog/entry/94896
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main() {
    std::cout << lcm(1'000'000'000, 1'000'000'001) << "\n";
}
