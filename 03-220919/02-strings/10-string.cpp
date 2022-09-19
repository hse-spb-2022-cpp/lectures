#include <iostream>
#include <string>

int main() {
    std::string a = "hello";
    a += "world";
    std::cout << a << '\n';

    a[2] = 'X';  // unlike Java
    std::cout << a << '\n';

    // compilation error: legacy, string literal is not really a string
    // https://en.cppreference.com/w/cpp/language/string_literal
    std::string a_bad = "hello" + "world";
    [[maybe_unused]] std::string a_wtf = "hello" "world";  // ok, but why? Literals only
    [[maybe_unused]] auto a_no_auto = "hello";
    a_no_auto += "world";

    // Very like vector:
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
