#include <cassert>

struct ratio {
    // Invariant: denom != 0
    int num;
    int denom;

    ratio() : num(0), denom(1) {}
    ratio(int value) : num(value), denom(1) {}
    ratio(int num_, int denom_) : num(num_), denom(denom_) {
        assert(denom != 0);
    }
    double to_double() const {
        return num * 1.0 / denom;
    }
};

int main() {
    ratio r;
    // API design principle: it should be impossible to
    // "break" the class even if you want!
    // Violated:
    r.denom = 0;
}
