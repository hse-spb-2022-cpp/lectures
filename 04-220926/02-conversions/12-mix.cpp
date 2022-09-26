// Does not compile because of 'reasons'
struct Foo {
    operator Bar() {  // Compiler does not know about `Bar` yet
        return Bar{};
    }
};

struct Bar {
    Bar() {}
    Bar(Foo /*arg*/) {}
};

int main() {
    Foo f;
    Bar b = f;  // ambiguous
}
