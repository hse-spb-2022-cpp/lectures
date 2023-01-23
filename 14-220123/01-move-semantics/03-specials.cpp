#include <iostream>
#include <utility>

struct Foo {
    Foo() {
        std::cout << "Foo() " << this << "\n";
    }

    // https://en.cppreference.com/w/cpp/language/rule_of_three
    // Rule of zero: do not implement any of these.
    // https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rc-zero
    // Rule of five: if one is implemented, implement all five.
    // https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c21-if-you-define-or-delete-any-copy-move-or-destructor-function-define-or-delete-them-all
    Foo(const Foo &other) {  // copy constructor: direct init, copy init...
        std::cout << "Foo(const Foo&) " << this << " <- " << &other << "\n";
        /* lvalue */ other;
    }

    Foo(Foo &&other) {  // move constructor: same, but initialized from rvalue
        std::cout << "Foo(Foo&&) " << this << " <- " << &other << "\n";
        /* lvalue */ other;
    }

    Foo& operator=(const Foo &other) {
        std::cout << "operator=(const Foo&) " << this << " = " << &other << "\n";
        return *this;
    }

    Foo& operator=(Foo &&other) {
        std::cout << "operator=(Foo&&) " << this << " = " << &other << "\n";
        return *this;
    }

    ~Foo() {
        std::cout << "~Foo() " << this << "\n";
    }
};

void call_by_value(Foo f) {
    std::cout << "call_by_value " << &f << "\n";
}

Foo create_foo() {
    Foo f;
    std::cout << "create_foo " << &f << "\n";
    return f;  // `f` is local variable => considered rvalue, please do not std::move it, details later.
}

int main() {
    Foo a;
    Foo b(/* lvalue */ a);  // Foo b = a
    Foo c(/* xvalue */ std::move(a));  // Foo c = std::move(a);
    Foo d;

    b = /* lvalue */ d;
    b = /* xvalue */ std::move(d);

    std::cout << "===== call 1 =====\n";
    call_by_value(/* lvalue */ a);

    std::cout << "===== call 2 =====\n";
    call_by_value(/* xvalue */ std::move(a));

    // Copy elision: copies/moves may be optimized out even if there are side effects, details are for later.
    std::cout << "===== call 3 =====\n";
    call_by_value(/* prvalue */ create_foo());

    std::cout << "===== dtors =====\n";
}
