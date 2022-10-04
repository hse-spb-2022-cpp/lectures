// These are two independent overloads.
void foo(int);
void foo() {
}

int main() {
    foo();
    foo(10);
}
