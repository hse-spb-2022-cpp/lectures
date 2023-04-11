#include <utility>

struct Foo {
    Foo(const Foo &other) = default;
    Foo &operator=(const Foo &other) = default;

    // Moves are typically noexcept
    Foo(Foo &&other) noexcept = default;
    Foo &operator=(Foo &&other) noexcept = default;

    void modify1() {   // basic exception safety
        // ...
    }
    void modify2() {   // basic exception safety
        // ...
    }
    void modify3() {   // basic exception safety
        // ...
    }

    void modify123() {  // strong exception safety
         Foo f = *this;  // copy, can throw, does not matter
         // Following operations can throw, but they only spoil `f`
         f.modify1();
         f.modify2();
         f.modify3();
         // Move is noexcept
         *this = std::move(f);
    }
};

int main() {
}
