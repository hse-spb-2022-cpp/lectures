// Since C++14
auto fib(int n) {
    if (n <= 1) {
        return 1;  // first return, deduced int
    } else {
        return fib(n - 1) + fib(n - 2);  // ensured: it is int
    }
}

auto fib_bad(int n) {
    if (n > 1) {
        return fib_bad(n - 1) + fib_bad(n - 2);  // first return, cannot deduce
    } else {
        return 1;
    }
}

auto inconsistent_deduction() {
    return 1;
    return 'x';  // 'int' and 'char' can be implicitly converted, but are not the same type
}

struct Foo {};

auto returning_initializer_list() {
    return Foo();
    return {};  // still compilation error
}

void do_something() {}

auto return_void() {
    return do_something();  // ok, returning void, but should not be `auto&`
}
