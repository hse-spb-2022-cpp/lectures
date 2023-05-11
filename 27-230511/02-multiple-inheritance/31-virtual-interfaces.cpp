#include <string>
#include <iostream>

// WARNING: not a good example below!
// Extra reading: https://isocpp.org/wiki/faq/multiple-inheritance#mi-not-evil

// Interfaces: inheritance from interface is always virtual
struct Object {
    int id() const { return id_; }
    virtual ~Object() {}

private:
    int id_;
};

struct Formattable : virtual Object {
    virtual std::string format() const = 0;
};

struct Readable : virtual Object {
    virtual void read(std::istream &) = 0;
};

struct FormattableReadable : virtual Formattable, virtual Readable {};

// Objects
struct Foo : virtual Formattable {
    std::string format() const override {
        return "foo";
    }
};

struct Bar : virtual Readable {
    void read(std::istream &) override {
        std::cout << "read\n";
    }
};

struct FooBar : Foo, Bar, virtual FormattableReadable {};

int main() {
    FooBar object;
    FormattableReadable &fr = object;
    std::cout << fr.format() << "\n";
    fr.read(std::cin);
}
