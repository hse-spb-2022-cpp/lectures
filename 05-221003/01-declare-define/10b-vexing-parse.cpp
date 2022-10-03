struct Bar {
    explicit Bar() {}
};
struct Foo {
    explicit Foo(Bar) {}
};

int main() {
    // Foo f(Bar());  // the most vexing parse: Foo f(Bar (*arg) ())
    // Foo f{Bar()};
    // Foo f(Bar{});
    // Foo f{Bar{}};
    // Foo f((Bar()));
    Foo f(   (Bar())  );
    f = f;
}

// Foo f( (int x) ) {}
