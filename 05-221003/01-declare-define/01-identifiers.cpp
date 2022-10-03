// https://stackoverflow.com/a/228797/767632
// https://codeforces.com/blog/entry/17747

struct foo_t {  // '_t', not UB, but reserved by POSIX.
};

int _;  // UB
int _z;  // UB

int main() {
    // int true = 10;  // No keywords
    // int 10fff = 20;  // Not start with a digit

    [[maybe_unused]] int x__b = 30;  // UB
    int _Xy;  // UB
    int _, _x;  // OK, but no.
}
