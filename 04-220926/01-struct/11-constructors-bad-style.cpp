#include <iostream>

struct ratio {
    int num;
    int denom;
    ratio() {  // default constructor
        num = 0;
        denom = 1;
        std::cout << "Default constructor\n";
    }
    ratio(int value) {
        num = value;
        denom = 1;
        std::cout << "ratio(int)\n";
    }
};

int main() {
    {
        ratio r;  // default initialization
        std::cout << r.num << "\n";
        std::cout << r.denom << "\n";
        
        ratio r2{};  // default initialization/list initialization
        std::cout << r2.num << "\n";
        std::cout << r2.denom << "\n";

        std::cout << ratio{}.num << "\n";
        std::cout << ratio().num << "\n";
    }

    {
        ratio r(10);  // direct initialization
        std::cout << r.num << "\n";
        std::cout << r.denom << "\n";

        ratio r2{10};  // direct list initialization
        std::cout << r2.num << "\n";
        std::cout << r2.denom << "\n";

        // TODO
        // Who is completed first: first << or constructor?
        // C++17: behavior is defined;
        // Before C++17: behavior is implementation-defined(???)
        std::cout << "a>" << ratio{10}.num << "<\n";
        std::cout << "b>" << ratio(10).num << "<\n";
    }
}
