template<typename T>
struct MyTemplate {
private:
    int x = 0;

    // (3)(bad) For all T: generate an independent non-template non_templ_friend(MyTemplate<int>, MyTemplate<void>) which is a friend of MyTemplate<T>.
    // Redefinition, ODR violation, inline does not help.
    friend void non_templ_friend(MyTemplate<int> &val, MyTemplate<void> &weird) {
        val.x = 10;
        weird.x = 10;  // Should not compile, but GCC compiles it anyway. Clang does not.
    }
};

int main() {
    MyTemplate<int> val1;
    MyTemplate<char> val2;
    MyTemplate<void> weird;

    MyTemplate<int> val1b;
    // non_templ_friend(val1, val1b);  // val1b is not <void>
    non_templ_friend(val1, weird);  // T=int
    non_templ_friend(val2, weird);  // T=char
    non_templ_friend(weird, weird);  // T=void
}
