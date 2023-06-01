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
    /*
    // Inefficient: extra construction, extra destruction
    void operator()(std::string x) {
        std::cout << "  store copy\n";
        stored = std::move(x);
    }
    */
    // Efficient: only one assignment (copy or move)
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
void log(Fn fn, Arg arg) {
    std::cout << "start\n";
    fn(std::move(arg));
    std::cout << "end\n";
}

int main() {
    log(foo, 10);

    int x = 20;
    // log(bar, x);  // compilation error :(
    log(bar, std::ref(x));  // Requires std::ref at call place
    std::cout << "x = " << x << "\n";

    std::string s = "hello world from long string";
    const std::string cs = "hello world from long const string";
    Storer baz;
    log(baz, s);  // 1 copy ctor, 1 move assignment, 1 destructor.
    log(baz, std::move(s));  // 1 move ctor, 1 move assignment, 1 destructor.
    log(baz, std::ref(s));  // 1 copy assignment
    // log(baz, std::ref(std::move(s)));  // Unsupported.
    log(baz, cs);  // 1 copy, 1 move, 1 destructor.
    log(baz, std::move(cs));  // 1 copy, 1 move, 1 destructor.

    // Two problems:
    // 1. Lots of `std::ref`/`std::cref`
    // 2. No way to do just 1 move.
    // Underlying reason: `log` creates an object, but references are enough.
    // Moreover, inspecting `fn` is impossible, it may even have overloads.
}
