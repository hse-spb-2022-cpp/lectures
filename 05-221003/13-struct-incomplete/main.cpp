struct Foo;

// Incomplete type is enough for references/pointers passing.
// Sometimes even STL containers support incomplete types, check cppreference.
Foo& get_foo();
void call_method(Foo &f);

int main() {
    call_method(get_foo());
    Foo &f = get_foo();
    // f.method();  // Need complete type: is there even a `method`?

    // Foo g = get_foo();  // Need complete type: have to allocate a place for `Foo`.
}
