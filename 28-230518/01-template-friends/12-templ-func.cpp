template<typename T>
struct MyTemplate {
private:
    int x = 0;

    // (4) For all T: for all U: foo(MyTemplate<U>&, MyTemplate<void>&) is a friend of MyTemplate<T>
    template<typename U>
    friend void foo(MyTemplate<U> &, MyTemplate<void> &);
};

template<typename U>
void foo(MyTemplate<U> &val, MyTemplate<void> &weird) {
    val.x = 10;
    weird.x = 10;
}

int main() {
    MyTemplate<int> val1;
    MyTemplate<char> val2;
    MyTemplate<void> weird;

    foo(val1, weird);
    foo(val2, weird);
}
