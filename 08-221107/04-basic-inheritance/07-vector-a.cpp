#include <iostream>
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

int main() {
    std::vector<Printable*> v;

    Int i;
    i.x = 10;

    String s;
    s.s = "hello";

    v.push_back(&i);
    v.push_back(&s);

    for (auto &el : v) {
        print(*el);
    }
}

std::vector<Printable*> bad_create_vector() {
    std::vector<Printable*> v;
    Int i;
    i.x = 10;
    v.push_back(&i);
    return v;
}
