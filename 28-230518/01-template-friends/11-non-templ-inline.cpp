template<typename T>
struct MyTemplate {
private:
    int x = 0;

    // (3) For all T: generate an independent non-template non_templ_friend(MyTemplate<T>, MyTemplate<void>) which is a friend of MyTemplate<T>.
    // Ok, strictly better than (2).
    friend void non_templ_friend(MyTemplate &val, MyTemplate<void> &weird) {
        val.x = 10;
        weird.x = 10;  // Should not compile, but GCC compiles it anyway. Clang does not.
        // See https://gcc.gnu.org/bugzilla/show_bug.cgi?id=109923
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
