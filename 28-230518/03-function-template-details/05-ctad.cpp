#include <utility>

// C++17: class template argument deduction (CTAD)
template<typename TA, typename TB>
struct pair {
    TA a;
    TB b;

    pair() {}
    pair(TA a_) : a(std::move(a_)) {}  // Will not be used by CTAD by default: unable to deduce TB.
    pair(TA a_, TB b_) : a(std::move(a_)), b(std::move(b_)) {}
};
// CTAD needs two things:
// 1. Deduce class(!) template arguments from constructor arguments.
// 2. Choose appropriate constructor. Note that constructors may be templated themselves.

// "Deduction guides" for (1) are generated from constructors by default: https://en.cppreference.com/w/cpp/language/class_template_argument_deduction
// template<typename TA, typename TB> pair(TA, TB) -> pair<TA, TB>;
// Can also add explicit deduction guide:
// template<typename TA> pair(TA) -> pair<TA, int>;  // (XXX)

template<typename TA, typename TB>
pair<TA, TB> make_pair(TA a_, TB b_) {
    return {std::move(a_), std::move(b_)};
}

int main() {
    [[maybe_unused]] auto p1 = pair(10, 20);
    [[maybe_unused]] pair p2(10, 20);
    [[maybe_unused]] pair<double, int> p3(10, 20);
    // [[maybe_unused]] pair<double, int> p4 = pair(50.0);  // Works only if there is deduction guide (XXX).
    // [[maybe_unused]] pair<double> p5(10, 20);  // Either all arguments are specified, or use full CTAD only. No partial.

    // Work around + life before C++17: using argument deduction for functions.
    [[maybe_unused]] auto p5 = make_pair(10, 20);
    [[maybe_unused]] auto p6 = make_pair<double>(10, 20);

    struct ConvertibleToPair {
        operator pair<int, double>() { return {10, 20.5}; }
    };
    // [[maybe_unused]] pair p7 = ConvertibleToPair{};  // CTAD does not work through conversions, guides are pre-generated.
    [[maybe_unused]] pair<int, double> p8 = ConvertibleToPair{};
}
