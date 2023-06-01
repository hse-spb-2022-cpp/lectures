#include <iostream>

struct Foo {
    void operator()() & {
        std::cout << "lvalue\n";
    }
    void operator()() && {
        std::cout << "rvalue\n";
    }
};

template<typename Fn>
void call(Fn &&fn) {
    std::forward<Fn>(fn)();  // Rarely done in STL: it assumes functors are trivial. Should actually be done.
}

int main() {
    Foo f;
    f();  // lvalue
    Foo()();  // rvalue
    call(f);  // lvalue
    call(Foo());  // should call operator() &&
}
