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

// Almost solution: overload `log` based on value category of each argument: lvalue/rvalue.
// We can actually do overload.
template<typename Arg, typename Fn>
void log(Fn fn, Arg &arg) {
    std::cout << "start (1)\n";
    fn(arg);
    std::cout << "end\n";
}

template<typename Arg, typename Fn>
void log(Fn fn, Arg &&arg) {  // not really rvalue reference, but just you wait.
    std::cout << "start (2)\n";
    fn(std::move(arg));
    std::cout << "end\n";
}

int main() {
    log_rvalue(foo, 10);

    int x = 20;
    log_lvalue(bar, x);  // No more std::ref
    std::cout << "x = " << x << "\n";

    std::string s = "hello world from long string";
    const std::string cs = "hello world from long const string";
    Storer baz;
    log_lvalue(baz, s);  // 1 copy assignment
    log_rvalue(baz, std::move(s));  // 1 move assignment
    log_lvalue(baz, cs);  // 1 copy assignment
    log_rvalue(baz, std::move(cs));  // 1 copy (because it's rvalue reference to const)
    // Problem: two implementations of `log`.
}
