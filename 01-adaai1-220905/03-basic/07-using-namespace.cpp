#include <iostream>

// To the compiler: when unable to find X, check for std::X as well.
// Typically each library has its own "namespace", `std` is for the standard C++ library.
// Bad style: lots of stuff in `std`, and more gets added with each standard.
using namespace std;

int main() {
    int a, b;
    // Helps in olympiads: less to type, do not care about other compilers or newer standards.
    cin >> a >> b;
    cout << a << b;
}
