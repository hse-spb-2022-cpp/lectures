#include <cassert>
#include <iostream>
#include <vector>
#include <memory>
#include <utility>

struct Foo {
    std::vector<int> v;

    Foo() : v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10} {}
};

std::unique_ptr<Foo> create_foo() {
    auto f = std::make_unique<Foo>();
    assert(f->v[2] == 3);
    return f;  // Can return local variables
}

auto global_f = std::make_unique<Foo>();
std::unique_ptr<Foo> create_foo_bad() {
    return std::move(global_f);  // But why?
    // return std::make_unique<Foo>(*global_f);  // deep copy
}

int main() {
    std::vector<std::unique_ptr<Foo>> vec;
    {
        vec.emplace_back(create_foo());  // No std::move needed

        auto f = create_foo();
        // vec.emplace_back(f);

        std::unique_ptr<Foo> g = std::move(f);
        assert(f == nullptr);
        vec.emplace_back(std::move(g));
        assert(g == nullptr);

        std::cout << vec[0]->v[4] << "\n";
        std::cout << vec[1]->v[4] << "\n";
        std::cout << (g == nullptr) << "\n";
    }
    std::cout << vec[0]->v[4] << "\n";
}
