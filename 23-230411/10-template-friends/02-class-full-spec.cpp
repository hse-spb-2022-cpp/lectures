#include <vector>
#include <utility>

template<typename T>
struct Bar;

template<typename T>
struct Foo {
private:
    int x = 0;

    // One specific Bar<> is a friend. No way to partially specialize.
    friend struct Bar<std::vector<T>>;
};

template<typename U /* VecT may be a better name to avoid confusion */>
struct Bar {
    void bar() {
        // Foo<int>: friend struct Bar<vector<int>>.

        // Foo<int> f;
        Foo<typename U::value_type> f;
        f.x = 10;

        // U is never vector<void>
        [[maybe_unused]] Foo<void> g;
        // g.x = 10;

        // U is never vector<U>
        [[maybe_unused]] Foo<U> h;
        // h.x = 10;
    }
};

int main() {
    Bar</*U=*/std::vector<int>>().bar();
    Bar</*U=*/std::vector<char>>().bar();
//    Bar</*U=*/int>().bar();
}
