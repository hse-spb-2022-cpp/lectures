template<typename T>
struct foo {
    int y = 1;
    void bar() {
        /*typename*/ T::x *y;
        /*typename*/ T::x * y;
    }
};

struct with_int { static inline int x = 5; };
foo<with_int> f_int;

struct with_type { using x = char; };
foo<with_type> f_type;

int main() {
    f_int.bar();
    f_type.bar();  // Does not compile, needs 'typename' before 'T::x'
}
