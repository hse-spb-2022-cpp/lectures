template<typename T>
struct MyTemplate {
private:
    int x = 0;

    // (1) Non-template declaration
    friend void simple_func();

    // (2) For all T: generate an independent non-template non_simple_func(MyTemplate<T>&) declaration, impossible to define outside the class in general.
    // Warning.
    friend void non_simple_func(MyTemplate&);
    // friend void non_simple_func(MyTemplate<T>&);
};

void simple_func() {
    MyTemplate<int> val1;
    val1.x = 10;
}

// Template non_simple_func<T>(), does not correspond to a non-template declaration inside MyTemplate.
template<typename T>
void non_simple_func([[maybe_unused]] MyTemplate<T> &val) {
    // val.x = 10;
}

// Non-template non_simple_func
void non_simple_func(MyTemplate<int> &val) {
    val.x = 10;
}

int main() {
    MyTemplate<int> val1;
    MyTemplate<char> val2;
    MyTemplate<void> weird;

    non_simple_func(val1);  // Calls global function, ok
    non_simple_func<int>(val1);  // Attempts to call the template function, it is not a friend.
    non_simple_func(val2);  // Calls global function by its friend declaration, undefined reference.
}
