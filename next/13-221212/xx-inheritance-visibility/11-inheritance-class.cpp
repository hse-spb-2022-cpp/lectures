class Base {
public:
    void foo() {
    }
};

class Derived : /* private */ Base {};  // Not OK?
// class Derived : public Base {};  // OK
// struct Derived : /* public */ Base {};  // OK

int main() {
    Derived d;
    d.foo();
}
