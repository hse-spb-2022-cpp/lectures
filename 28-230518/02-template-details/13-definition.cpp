template<typename T>
struct Foo {
    void foo(const Foo &other);
    Foo create_foo();
    static int static_field;

    template<typename U, typename V>
    void bar();
};

template<typename T>
void Foo<T>::foo(const Foo &) {
}

template<typename T>
Foo<T> Foo<T>::create_foo() {
}

template<typename T>
int Foo<T>::static_field = 10;

template<typename T>  // Class template arguments
template<typename U, typename V>  // Function template arguments
void Foo<T>::bar() {
}

int main() {
    Foo<int> x;
    x.foo(x);

    Foo<char>::static_field = 10;
}
