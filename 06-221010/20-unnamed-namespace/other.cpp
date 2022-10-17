#include <iostream>
#include "other.hpp"

// "unnamed namespace"
namespace {
// internal linkage
void foo() {
    std::cout << "other foo\n";
}
}  // namespace

// default: external linkage
void do_other() {
    foo();
}
