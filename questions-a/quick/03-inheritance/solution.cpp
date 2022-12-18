#include <string>
#include <memory>
#include <vector>
#include <iostream>

struct Base {
    virtual std::string to_string() const;
    virtual ~Base() {}
};

struct Str : Base {
    std::string s;
    Str(std::string s_) : s(std::move(s_)) {}
    std::string to_string() const override {
        return s;
    }
};

struct Int : Base {
    int x;

    Int(int x_) : x(x_) {}
    std::string to_string() const override {
        return std::to_string(x);
    }
};

int main() {
    std::vector<std::unique_ptr<Base>> v;
    v.emplace_back(std::make_unique<Str>("hello"));
    v.emplace_back(std::make_unique<Int>(10));

    for (auto &x : v) {
        std::cout << x->to_string() << "\n";
    }
}
