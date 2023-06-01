#include <functional>
#include <iostream>
#include <string>

void foo(int x) {
    std::cout << "  foo(" << x << ")\n";
}

void bar(int &x) {
    std::cout << "  bar(" << x << ")\n";
    x++;
}

struct Storer {
    std::string stored;
    void operator()(const std::string &x) {
        std::cout << "  store copy\n";
        stored = x;
    }
    void operator()(std::string &&x) {
        std::cout << "  store move\n";
        stored = std::move(x);
    }
};

template<typename Arg, typename Fn>
void log(Fn fn, Arg &&arg) { // Special `Arg` deduction rules: "forwarding reference".
    // Assume the argument's type is `T`. Its value category is either:
    // * Rvalue: Arg = T , Arg&& = T&&
    // * Lvalue: Arg = T&, Arg&& = T&  (reference collapse rules: & + && = &, non-temporary wins)
    std::cout << "start\n";
    // std::forward<Arg> ~ static_cast<Arg&&>:
    // * Rvalue: Arg = T , Arg&& = T&&, std::forward ~ static_cast<T&&> ~ std::move
    // * Lvalue: Arg = T&, Arg&& = T& , std::forward ~ static_cast<T&>  ~ no-op !!!
    fn(std::forward<Arg>(arg));
    // Notes:
    // 1. Not `std::move`: it always returns T&& (rvalue).
    // 2. `arg` is always lvalue of type `T`, so no automatic deduction is possible. Hence,
    //    the explicit template argument is required.
    // Alternative: `std::forward<Arg&&>(arg)`, `std::forward<decltype(arg)>(arg)`.
    std::cout << "end\n";
}

int main() {
    log(foo, 10);  // Rvalue: Arg=int, Arg&&=int&&

    int x = 20;
    log(bar, x);  // Lvalue: Arg=int&, Arg&&=int&
    std::cout << "x = " << x << "\n";

    std::string s = "hello world from long string";
    const std::string cs = "hello world from long const string";
    Storer baz;
    log(baz, s);  // Lvalue: Arg=std::string&, Arg&&=std::string&
    log(baz, std::move(s));  // Rvalue: Arg=std::string, Arg&&=std::string&&
    log(baz, cs);  // Lvalue: Arg=const string&, Arg&&=const string&
    log(baz, std::move(cs));  // Rvalue: Arg=const string, Arg&&=const string&&
}
