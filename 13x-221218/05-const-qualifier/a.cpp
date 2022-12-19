struct Foo {
    int x = 10;

    // void foo(const Foo *this, int &y, int z) {
    void foo(int &y, int z) const {
        // x++;  // prohibited by const qualifier
        y++;
        z++;
    }
};

int main() {
    Foo f;
    int y = 40, z = 50;
    f.foo(y, z);
    std::cout << y << " " << z << "\n";
}
