struct Base {
    virtual void foo() = 0;
    virtual void bar() = 0;
};

struct Derived : Base {
    void foo() final {  // final needs 'virtual'
    }

    // 'override' is redundant:
    // void fooo() final {}  // CE, which is fine.
    // virtual void fooo() final {}  // Not CE, which is not fine.

    void bar() override {
    }
};

struct SubDerived : Derived {
    // 'override' is not important, will not compile either way.
    // void foo() {}

    void bar() override {
    }
};

int main() {
}
