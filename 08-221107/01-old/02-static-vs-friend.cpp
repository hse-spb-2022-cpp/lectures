struct Foo {
private:
    int x;

private:
    friend void foo(Foo &f);  // 1(a). not affected by private/public
    static void bar(Foo &f);  // 1(b). affected by private/public

public:
    static void baz(Foo &f);
};

void foo(Foo &) {
}

void Foo::bar(Foo &f) {
    f.x = 10;
}

void Foo::baz(Foo &f) {
    bar(f);  // can access private
}

int main() {
    Foo f;

    // 2(a). Called as a usual function.
    foo(f);

    // 2(b). Called as a member function.
    // Foo::bar(f);  // cannot access private
    Foo::baz(f);
}
