#include <vector>

template<typename> struct TD;

int& foo();
int&& bar();

int main() {
    int x = 10;
    int &y = x;

    // decltype() has two modes:
    // 1. decltype(expression)
    TD<decltype(10)>();  // int
    TD<decltype( (x) )>();  // int&
    TD<decltype( (y) )>();  // int&
    TD<decltype( x + 20 )>();  // int
    TD<decltype( foo() )>();  // int&
    TD<decltype( bar() )>();  // int&&
    // Returns depending on value category: T (prvalue), T& (lvalue), T&& (xvalue)
    // Reminder: rvalue = prvalue || xvalue

    // 2. decltype(name) - a variable/field/argument with no parens
    TD<decltype(x)>();  // int
    TD<decltype(y)>();  // int&
    // Returns: the declaration of `name`

    // In either mode: nothing is evaluated:
    std::vector<int> v;
    decltype(*v.begin()) v_value = 10;
}
