template<typename T>
struct MyTemplate {
private:
    int x = 0;

    // (4)(bad) For all T: for all U: foo(MyTemplate<U>&, MyTemplate<void>&) is a friend of MyTemplate<T>
    // Each `MyTemplate<T>` generates a new definition, ODR violated.
    template<typename U>
    friend void foo(MyTemplate<U> &val, MyTemplate<void> &weird) {
        val.x = 10;
        weird.x = 10;
    }
};

int main() {
    MyTemplate<int> val1;  // Everything compiles if commented
    MyTemplate<void> weird; 
}
