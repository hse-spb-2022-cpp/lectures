struct Bar {
    explicit Bar() {}
};
struct Foo {
    explicit Foo(Bar) {}
};

struct Botva {
    Foo f(Bar());  // oops, function
    // TODO

    void foo() {
        f = f;
    }
};

int main() {
    Foo f(Bar());  // the most vexing parse: Foo f(Bar (*arg) ())
    // Foo f{Bar()};
    // Foo f(Bar{});
    // Foo f{Bar{}};
    // Foo f((Bar()));  // C++03 and before
    // Foo f(   (Bar())  );  // C++03 and before
    f = f;
}

// Foo f( (int x) ) {}
