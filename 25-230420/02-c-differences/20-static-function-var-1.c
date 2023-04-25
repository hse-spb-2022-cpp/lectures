void foo(void);
void bar(void);

extern int x;
extern int y;

int main(void) {
    foo();
    bar();
    x = 0;
    y = 0;
}
