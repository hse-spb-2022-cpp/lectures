struct my_vector {
    my_vector() {}
    my_vector(int) {}
};

void print_vector([[maybe_unused]] const my_vector &vec) {
}

int main() {
    [[maybe_unused]] my_vector v1(10);
    [[maybe_unused]] my_vector v2 = 10;  // copy initialization, should not work
    print_vector(10);  // copy initialization, should not work
}
