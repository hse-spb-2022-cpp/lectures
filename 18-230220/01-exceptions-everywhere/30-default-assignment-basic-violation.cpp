#include <cassert>
#include <iostream>
#include <vector>

// See exercise `17-230214`, `30-copy-no-basic-guarantee`
// https://stackoverflow.com/questions/13341456/exception-safety-of-c-implicitly-generated-assignment-operator

int throw_after = 1;

struct VectorHolder {
    std::vector<int> data;
    VectorHolder(int n, int val) : data(n, val) {}

    VectorHolder &operator=(const VectorHolder &other) {
       if (--throw_after < 0) {
           throw 0;
       }
        data = other.data;
        return *this;
    }
};

struct Foo {
private:
    VectorHolder a;
    VectorHolder b;

public:
    Foo(int n) : a(n, 1), b(n, 2) {}
    void check() {
        assert(a.data.size() == b.data.size());
    }
    // Oops: implicitly generated operator= assigns fields one-by-one.
};

int main() {
    Foo x(10);
    Foo y(20);
    x.check();
    y.check();
    try {
        x = y;
        // x.a = y.a;
        // x.b = y.b;
    } catch (...) {
        std::cout << "caught\n";
    }
    x.check();  // invariant violated?
}
