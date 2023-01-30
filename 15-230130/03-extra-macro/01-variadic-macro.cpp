// Compile with `g++ -E` to see preprocessed output.

// variadic macro
#define foo(a, b, ...) bar(b, a, __VA_ARGS__)

int main() {
    foo(1, 2, 3, 4);
    foo(1, 2, 3);

    // Oopses:
    foo({1, 2, 3, 4});
    foo(({1, 2, 3, 4}), 5, 6);
    foo(1, 2);  // Can be fixed with C++20's __VA_OPT__ or GCC's extension of ##.
    foo(std::map<int, int>(), std::map<int, int>());
    foo((std::map<int, int>()), (std::map<int, int>()));

    // TODO: Compilation error
    foo((std::map<int, int>()));
}
