// template<typename T>
// struct Bar;

template<typename T>
struct Foo {
private:
    int x = 0;

    // All Bar<> are friends of us.
    template<typename/* U*/>
    friend struct Bar;
};

template<typename T>
struct Bar {
    void bar() {
        Foo<T> f;
        f.x = 10;

        Foo<void> g;
        g.x = 10;
    }
};

int main() {
    Bar<int>().bar();
}
