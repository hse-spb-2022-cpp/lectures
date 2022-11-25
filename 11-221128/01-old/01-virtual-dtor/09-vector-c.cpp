#include <iostream>
#include <memory>
#include <vector>
#include <string>

struct Printable {  // 'abstract' class because at least one 'pure virtual' function
    virtual void print() const = 0;  // pure virtual
};

struct Int : Printable {
    int x = 0;

    void print() const override {
        std::cout << x << "\n";
    }
};

struct String : Printable {
    std::string s;

    void print() const override {
        std::cout << s << "\n";
    }
};

void print(const Printable &p) {
    p.print();
}

std::vector<std::unique_ptr<Printable>> create_vector() {
    std::vector<std::unique_ptr<Printable>> v;
    std::unique_ptr<Int> i = std::make_unique<Int>();
    i->x = 10;
    v.push_back(std::move(i));

    std::unique_ptr<String> s = std::make_unique<String>();
    s->s = "hello";
    v.push_back(std::move(s));
    return v;
}

int main() {
    std::vector<std::unique_ptr<Printable>> v = create_vector();
    for (auto &el : v) {
        print(*el);
    }
    // UB because incorrect destructor is called; Address Sanitizer, gcc does not warn, clang does warn
}
