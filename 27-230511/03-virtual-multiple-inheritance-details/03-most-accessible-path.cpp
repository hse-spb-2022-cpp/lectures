struct Base {
    int data;
};

struct X : private virtual Base {
};

struct Y : public virtual Base {
};

struct X1 : X {
    void foo() {
        // data = 10;  // access through X, private
    }
};

struct Derived : X, Y {
    void foo() {
        data = 10;  // access is public through Y
        Y::data = 20;  // accessible as well, not surprising
        X::data = 30;  // accessible as well, wow
    }
};

int main() {
}
