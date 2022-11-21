#include <memory>

// https://abseil.io/tips/134

struct Foo {
    static std::unique_ptr<Foo> make() {
        // return std::make_unique<Foo>();  // bad
        return std::unique_ptr<Foo>(new Foo());  // good
    }

private:
    Foo() {}

    // Technically possible, but won't help becase std::make_unique may construct indirectly
    // friend std::unique_ptr<Foo> std::make_unique<Foo>();
};

int main() {
    // auto p1 = std::make_unique<Foo>();  // hence, this is bad
    auto p2 = Foo::make();  // this is good
}
