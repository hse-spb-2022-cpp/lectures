auto foo();

auto bar() {
    return foo();
}

auto foo() {
    return bar();
}

int main() {}
