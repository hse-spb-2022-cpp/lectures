const int N = 100;  // C++ only
#define N 100  // C++ and C

struct Point {
   int x, y;
};
struct TwoPoints {
   Point a, b;  // C++ only
   struct Point a, b;  // C++ and C
};

int foo(int x = 100);  // C++ only
int foo(int x);  // C++ and C, no default arguments. At all.
