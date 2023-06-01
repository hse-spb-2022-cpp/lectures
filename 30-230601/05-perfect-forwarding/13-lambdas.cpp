#include <iostream>
#include <utility>

int sum(int a, int b) {
    return a + b;
}

int &get_int_ref() {
    static int x = 10;
    return x;
}

int main() {
    auto logged = [](auto fn, auto &&...args) -> decltype(auto) {
        std::cout << "started\n";
        decltype(auto) res = fn(std::forward<decltype(args)>(args)...);
        std::cout << "ended\n";
        return res;
    };

    int x = logged(sum, 2, 3);
    std::cout << "x=" << x << "\n";

    int &ref = logged(get_int_ref);
    std::cout << "ref=" << ref << "\n";
    ref += 10;
    std::cout << "ref2=" << logged(get_int_ref) << "\n";
}
