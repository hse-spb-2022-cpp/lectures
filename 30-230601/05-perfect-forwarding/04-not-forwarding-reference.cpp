template<typename T>
struct my_vector {
    void push_back_1(T &&) {  // not forwarding reference: `T` is already fixed. Just rvalue reference.
    }

    template<typename U>
    void push_back_2(U &&) {  // forwarding reference: `U` is deduced when calling
    }
};

template<typename T>
void foo(my_vector<T> &&) {  // not forwarding reference: argument is always rvalue, `T` cannot affect this
}
