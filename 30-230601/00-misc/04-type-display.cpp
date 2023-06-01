#include <string>

template<typename> struct TD;  // "Type Display" in a compilation error

int main() {
    TD<int>();
    TD<decltype(main)>();

    std::string s;
    TD<decltype(s)>();

    auto f = [](auto x) {
        TD<decltype(x)>();
    };
    f(10);
    f(10.5);
}
