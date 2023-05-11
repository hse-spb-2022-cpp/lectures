#include <iostream>
#include <sstream>

// Can be implemented in another translation unit.
// Dynamic polymorphism, not static!
int readInt(std::istream &is) {
    int x;
    is >> x;
    return x;
}

void printInt(std::ostream &os, int x) {
    os << x;
}

int main() {
    std::stringstream s1;
    std::iostream &s2 = s1;
    // iostream : istream, ostream
    printInt(s2, 10);
    printInt(std::cout, readInt(s2));
    std::cout << "\n";

    // needs virtual inheritance!
    // istream : virtual ios
    // ostream : virtual ios

    /*
          ios
         /   \
        /     \
    istream ostream
        \     /   \
         \   /     \
        iostream    \
           |         \
      stringstream   ostringstream
    */
    std::ios &base = s2;
    std::cout << static_cast<bool>(base) << "\n";
    std::cout << base.fail() << "\n";
    base.precision(10);  // shared between input and output. Good or bad?
    // Possible: `base.encoding(...)`, probably good to share.
}
