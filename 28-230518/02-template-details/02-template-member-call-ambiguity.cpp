struct with_templ_member {
    template<typename T>
    static int foo() { return 10; };
};

template<typename T>
struct Foo {
    void call_foo() {
        // T::foo<int>();
        // T::foo < int      >();  // compilation error: expected primary-expression before 'int'
                                   // i.e.. "cannot compare foo with int"
        T::template foo<int>();  // needs 'template'
    }
};

int main() {
    Foo<with_templ_member>().call_foo();
}
