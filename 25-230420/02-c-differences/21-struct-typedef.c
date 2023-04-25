// Everything here is valid C++

struct point1 {  // no 'class'
    int x;  // = 0  // no member initializers
    int y;

    // No: constructors, destructors, rule of five (everything is trivially copyable/movable), methods, operator overloading
    // No: private/public, inheritance
};
// Type name is 'struct point1', not 'point1'.
struct point1 p1a;  // Valid C++ as well.

// Create an alias or multiple. There is no `using`.
typedef struct point1 point1, *ppoint1;
// Similar to `int *a, *b;`
// Similar to `int a, *b;`
// using point1 = struct point1;
// using ppoint1 = struct point1*;

point1 p1b;
ppoint1 pp1b = &p1b;

// More common idiom
typedef struct point2 {
    int x;
    int y;
} point2, *ppoint2;
point2 p2;
ppoint2 pp2 = &p2;

// Instead of methods.
int point2_dist2(const struct point2 *p) {
    return p->x * p->x + p->y * p->y;
}

int main() {
    // point2_dist2(&p2);
}
