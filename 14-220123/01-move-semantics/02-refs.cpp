#include <utility>

int& foo() {
    static int z = 0;
    return z;
}

int bar() {
    static int z = 0;
    return z;
}

int& bad_foo() {
    int x = 10;
    return x;  // no lifetime extension! dangling reference.
}

int main() {
    int x = /* prvalue */ 10;
    x;  // lvalue
    std::move(x);  // xvalue

    // lvalue references, can only bind to lvalue
    int &x1 = /* should be lvalue */ ((((x))));
    int &x2 = /* should be lvalue */ foo();
    // int &x3 = /* prvalue, CE */ bar();
    // int &x4 = /* prvalue */ (/* lvalue */ x + /* prvalue */ 10 + /* prvalue */ bar());  // CE
    // int &x5 = /* xvalue is rvalue, CE */ std::move(x);

    // rvalue references, can only bind to rvalue (xvalue + prvalue)
    int &&y1 = /* prvalue */ 10;
    int &&y2 = /* prvalue */ bar();  // lifetime extension: lifetime of the temporary is extended to lifetime of y2
    int &&y2b = /* xvalue */ std::move(/* prvalue */ bar());  // no lifetime extension, accessing y2b is UB.
        // One should never move(prvalue).
    int &&y3 = /* xvalue */ std::move(x);
    // int &&y4 = /* lvalue, CE */ x;

    // const lvalue references, can bind anywhere for historical reasons.
    // "Rvalue lifetime disaster": https://www.youtube.com/watch?v=zzkpTbJiFPM
    const int &z1 = /* lvalue */ x;
    const int &z2 = /* prvalue */ 10;  // lifetime extension
    const int &z3 = /* xvalue */ std::move(x);  // move(x) == static_cast<int&&>(x)
    const int &z4 = bar();  // lifetime extension

    // Also possible, but mostly useless.
    const int &&zz1 = 10;
    // const int &&zz2 = x1;

    int (&(zzz)) = x;  // Just weird declaration syntax.
    ((x)) = 20;
}
