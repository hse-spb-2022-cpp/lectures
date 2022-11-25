#include <iostream>
#include <vector>
#include <string>

struct Printable {
    virtual void print() const = 0;
    virtual ~Printable() {};  // !!! VIRTUAL DESTRUCTOR
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

std::vector<Printable*> create_vector() {
    std::vector<Printable*> v;
    Int *i = new Int;
    i->x = 10;
    v.push_back(i);

    String *s = new String;
    s->s = "hello";
    v.push_back(s);
    return v;
}

int main() {
    std::vector<Printable*> v = create_vector();
    for (auto &el : v) {
        print(*el);
    }
    for (auto el : v) {
        delete el;  // No UB because virtual destructor is called
    }
}
