#include <iostream>

int main() {
    int n;
    std::cin >> n;
    if (n % 3 == 0 && n % 5 == 0) {
        std::cout << "FizzBuzz\n";
    } else if (n % 3 == 0 || n % 5 == 0) {
        std::cout << "Fizz or Buzz\n";
    }
    // Operator precedence: && is like *, || is like +:
    // https://en.cppreference.com/w/cpp/language/operator_precedence

    // Just to demonstrate negation, if-else would be better
    if (!(n % 3 == 0 || n % 5 == 0)) {
        std::cout << "Neither Fizz nor Buzz\n";
    }

    // Alternative operators are banned for us.
    if (not(n % 3 == 0 or n % 5 == 0)) {
        std::cout << "Neither Fizz nor Buzz\n";
    }

    if ("") {  // works, but does something weird
        std::cout << "Why is empty string truthful? We do not know yet\n";
    }
}
