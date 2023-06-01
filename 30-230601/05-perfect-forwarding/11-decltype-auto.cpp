int x;

auto foo() {  // int
    return x;
}

auto &foo_ref() {  // int&
    return x;
}

auto foo_ref_caller_bad() {  // int
    return foo_ref();
}

decltype(auto) foo_ref_caller_bad() {  // int&
    return foo_ref();
}

decltype(auto) bar() {  // int
    return x;
}

decltype(auto) baz() {  // int&
    return (x);
}

int main() {
}
