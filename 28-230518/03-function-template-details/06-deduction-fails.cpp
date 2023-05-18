#include <vector>

template<typename T>
struct BaseConstructorTag {};

template<typename T>
struct Base {
    Base() {}
    Base(BaseConstructorTag<T>) {}
};

struct Derived1 : Base<int> {};
struct Derived2 : Base<double> {};
struct Derived3 : Base<int>, private Base<double> {
};

struct ConvertibleToBase {
    operator Base<int>() {
        return {};
    }
    // Even more fun for compiler and you
    // template<typename T> operator T() { return {}; }
    // https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Return_Type_Resolver
};

template<typename T>
void foo(const Base<T> &) {
}

int main() {
    foo(Base<int>());
    foo(Derived1());
    foo(Derived2());
    foo<int>(Derived3());
    //foo(Derived3());  // compilation error: ambiguous base, even though Base<double> is private

    BaseConstructorTag<int> t;
    [[maybe_unused]] const Base<int> &tref = t;
    foo<int>(t);
    // foo(t);  // compilation error: cannot deduce T because compiler won't go through all possible constructors

    ConvertibleToBase x;
    [[maybe_unused]] const Base<int> &xref = x;
    foo<int>(x);
    // foo(x);  // compilation error: cannot deduce T because compiler won't go through all possible conversions
}
