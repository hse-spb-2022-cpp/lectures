struct Bar;  // incomplete type

struct Foo {
    operator Bar();
};

struct Bar {
    Bar() {}
    Bar(Foo /*arg*/) {}
};

Foo::operator Bar() {
    return Bar{};
}

int main() {
    Foo f;
    Bar b = f;  // ambiguous
}
