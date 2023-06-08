// "Trailing return type", syntax sugar
auto fib(int n) -> int {
    if (n > 1) {
        return fib(n - 1) + fib(n - 2);  // first return, cannot deduce, but it's ok
    } else {
        return 1;
    }
}

template<typename T>
struct my_set {
    struct iterator {};

    iterator begin();
    iterator end();

    my_set &self();
};

// Usual
template<typename T>
typename my_set<T>::iterator my_set<T>::begin() {
    return{};
}

// Shorter version: we are "inside" my_set<T> after ::, so we can use just `iterator`
template<typename T>
auto my_set<T>::end() -> iterator {
    return {};
}
// TODO: arguments for SFINAE.

// Another alternative:
template<typename T>
// my_set<T> &my_set<T>::self() {  // Option 1
auto my_set<T>::self() -> my_set& {  // Option 2
    return *this;
}

int main() {
    my_set<int> s;
    [[maybe_unused]] auto b = s.begin();
    [[maybe_unused]] auto e = s.end();
}
