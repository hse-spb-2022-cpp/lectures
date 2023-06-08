#include <algorithm>
#include <iostream>

// Function specialization is probably a bad idea: http://www.gotw.ca/publications/mill17.htm
// Use overloads instead.

// Dimov/Abrahams example:
template<typename T> void foo(T) { std::cout << "1\n"; }

// Not overload, specialization of foo(T). Does not participate in overload resolution!
template<> void foo(int *) { std::cout << "2\n"; }  // T = int*

template<typename T> void foo(T*) { std::cout << "3\n"; }

// template<> void foo(int *) { std::cout << "4\n"; }

int main() {
    int x = 10;
    foo(x);  // 1
    foo<int*>(&x);  // 2, two candidates: foo<int*>(int*) and foo<int*>(int**)
    foo<int>(&x);  // 3, two candidates: foo<int*>(int) and foo<int*>(int*)
    foo(&x);  // 3: two candidates: foo(T) and foo(T*), latter is better
}
