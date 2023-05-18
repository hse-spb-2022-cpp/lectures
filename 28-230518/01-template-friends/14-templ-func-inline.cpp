template<typename T>
struct MyTemplate {
private:
    int x = 0;

    // (5) For all T: generate an independent template non_templ_friend<U>(MyTemplate<T>, MyTemplate<U>) which is a friend of MyTemplate<T> for any U.
    // Combination of (3) and (4).
    template<typename U>
    friend void bar(MyTemplate &val, MyTemplate<U> &weird) {
        val.x = 10;
        weird.x = 10;  // Should not compile when T != U because it's not a friend of MyTemplate<T>. Both GCC and Clang agree.
    }
};

int main() {
    MyTemplate<int> val1;
    MyTemplate<char> val2;
    MyTemplate<void> weird;

    bar(val1, val1);  // T=int, U=int
    // bar(val1, weird);  // T=int, U=void
}
