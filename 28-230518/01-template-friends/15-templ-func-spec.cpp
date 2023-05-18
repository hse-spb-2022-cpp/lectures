template<typename T>
struct MyTemplate;

template<typename U>
void foo(MyTemplate<U> &val, MyTemplate<void> &weird);

template<typename T>
struct MyTemplate {
private:
    int x = 0;

    // For any T: foo<T> is friend of MyTemplate<T>
    friend void foo<>(MyTemplate<T> &val, MyTemplate<void> &weird);  // <> or <T> is mandatory.
    // friend void foo<T>(MyTemplate<T> &val, MyTemplate<void> &weird);  // <> or <T> is mandatory.

    // For any T: foo<T*> is friend of MyTemplate<T>
    friend void foo<>(MyTemplate<T*> &val, MyTemplate<void> &weird);  // <> or <T*> is mandatory.
};

template<typename U>
void foo(MyTemplate<U> &val, [[maybe_unused]] MyTemplate<void> &weird) {
    val.x = 10;
    weird.x = 10;  // Works with U=void or U=void*, but not U=int.
}

int main() {
    MyTemplate<int*> a;
    MyTemplate<void*> b;
    MyTemplate<void> c;
    foo(a, c);  // U=int*
    foo(b, c);  // U=void*
    foo(c, c);  // U=void
}
