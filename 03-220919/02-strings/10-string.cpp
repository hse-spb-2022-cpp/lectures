#include <iostream>
#include <string>

int main() {
    std::string a = "hello";
    a += "world";
    std::cout << a << '\n';

    a[2] = 'X';  // unlike Java
    std::cout << a << '\n';

    // compilation error: legacy, string literal is not really a string
    // `auto` here is not `std::string`, legacy
    [[maybe_unused]] auto a_no_auto = "hello";
    a_no_auto += "world";

    // https://en.cppreference.com/w/cpp/language/string_literal
    std::string a_bad = "hello" + "world";
    std::string a_good = std::string("hello") + "world";

    // ok, but why? Literals only
    [[maybe_unused]] std::string a_wtf = "hello" "world";
    [[maybe_unused]] std::string a_wtf_ce = "hello" a;  // compilation error

    // Very like vector<char>
    a.push_back('Z');
    a.pop_back();
    std::cout << a.size() << " " << a.length() << "\n";

    for (int i = 0; i < 1'000'000; i++) {
        a += 'x';  // push_back, O(1) amortized
    }
    std::cout << a.size() << "\n";

    for (int i = 0; i < 1'000'000; i++) {
        a = a + 'x';  // new temporary string, O(n), clang-tidy warns
    }
    std::cout << a.size() << "\n";
}
