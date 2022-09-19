#include <iostream>
#include <sstream>

int main() {
    {
        std::stringstream s;
        int x = 456;
        s << 123 << ' ' << x;

        std::string str = s.str();
        std::cout << str.size() << ">" << str << "<\n";

        int y, z;
        s >> y >> z;
        std::cout << "y=" << y << ", z=" << z << "\n";
    }
    {
        std::stringstream s(" -10 -20 ");
        int y, z;
        s >> y >> z;
        std::cout << "y=" << y << ", z=" << z << "\n";
    }
}
