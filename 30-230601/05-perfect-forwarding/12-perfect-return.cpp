#include <iostream>
#include <utility>

int sum(int a, int b) {
    return a + b;
}

int &get_int_ref() {
    static int x = 10;
    return x;
}

template<typename Fn, typename ...Args>
decltype(auto) logged(Fn fn, Args &&...args) {
    std::cout << "started\n";
    decltype(auto) res = fn(std::forward<Args>(args)...);
    std::cout << "ended\n";
    return res;
    // return (res);  // wrong
}

int main() {
    int x = logged(sum, 2, 3);
    std::cout << "x=" << x << "\n";

    int &ref = logged(get_int_ref);
    std::cout << "ref=" << ref << "\n";
    ref += 10;
    std::cout << "ref2=" << logged(get_int_ref) << "\n";
}
