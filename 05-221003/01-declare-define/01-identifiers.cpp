// https://stackoverflow.com/a/228797/767632
// https://codeforces.com/blog/entry/17747

// int true = 10;  // No keywords
// int 10fff = 20;  // Not start with a digit

int _;  // UB
int _z;  // UB
int z_;  // ok
int x__a = 30;  // UB
int _Xx;  // UB

struct foo_t {  // '_t', not UB, but reserved by POSIX.
};

int main() {
    int _, _x;  // OK, but no.
    int x__b = 30;  // UB
    int _Xy;  // UB
}
