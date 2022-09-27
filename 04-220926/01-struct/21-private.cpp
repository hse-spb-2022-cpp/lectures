#include <cassert>
#include <iostream>

struct ratio {
private:
    // Invariant: denom != 0
    int num;
    int denom;

    // methods can be here as well

public:
    // fields can be here as well

    ratio() : num(0), denom(1) {}
    ratio(int value) : num(value), denom(1) {}
    ratio(int num_, int denom_) : num(num_), denom(denom_) {
        assert(denom != 0);
    }
    double to_double() const {
        return num * 1.0 / denom;
    }

    // getter
    int numerator() const {
        return num;
    }
    int denominator() const {
        return denom;
    }
/*    // setter: no need actually
    void numerator(int new_value) {
        num = new_value;
    }
    void denominator(int new_value) {
        assert(new_value != 0);
        denom = new_value;
    }*/
};

int main() {
    ratio r;
    // r = {0, 0};
    // r.denom = 0;
    // r.denominator(0);
    r = {r.numerator(), 5};
    // r.denominator(5);
    std::cout << r.numerator() << "\n";
}
