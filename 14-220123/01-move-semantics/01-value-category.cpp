#include <iostream>
#include <utility>
#include <vector>

// https://en.cppreference.com/w/cpp/language/value_category
/*
Each expression has:

1. Non-reference(!) type.
2. Value category: 

┌────────────────────────────┐
│         glvalue            │
│      (Generalized Left)    │
│              ┌─────────────┼───────────────────┐
│              │             │      rvalue       │
│              │             │      (Right)      │
│ ┌──────┐     │ ┌─────────┐ │   ┌────────────┐  │
│ │lvalue│     │ │ xvalue  │ │   │  prvalue   │  │
│ │(Left)│     │ │(eXpired)│ │   │(Pure Right)│  │
│ └──────┘     │ └─────────┘ │   └────────────┘  │
└──────────────┴─────────────┴───────────────────┘

glvalue: "has name", can be polymorphic, has address.
rvalue: "can be moved from"

Special case: `void()`
*/

int get_value() {
    return 10;
}

int &get_ref() {
    static int x;
    return x;
}

int &&get_rvalue_ref() {
    static int x;
    return std::move(x);
}

const int &get_cref() {
    static int x;
    return x;
}

int *get_ptr() {
    static int x;
    return &x;
}

int main() {
    int a = 10;
    int arr[5]{};
    struct { int x, y; } s;
    std::vector<int> vec(10);

    // lvalue: "has name", "cannot be moved from because lives long enough"
    std::cin;
    a;
    get_ref();
    get_cref();  // type: const int
    *get_ptr();
    arr;
    arr[4];  // `arr` should be lvalue
    s.x;  // `s` should be lvalue

    // prvalue: does not have name, "temporary" object
    10;
    get_value();
    get_value() + 20;
    &a;
    static_cast<int>(10.5);
    // `this` is also a prvalue.
    []() { return 23; };

    // xvalue: will expire soon, but has name
    std::move(vec);
    std::move(vec)[9];
    std::move(s).x;
    static_cast<std::vector<int>&&>(vec);  // std::move is almost exactly that.
    get_rvalue_ref();
}
