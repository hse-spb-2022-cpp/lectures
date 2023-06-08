#include <cassert>
#include <iostream>
#include <sstream>
#include <string>



template<typename T> struct serialization_traits {
    static void serialize(std::ostream &os, const T &x) {      x.serialize(os); }
    static T deserialize(std::istream &is)              { T x; x.deserialize(is); return x; }
};

// The same for all trivially copyable types, copy-paste
template<> struct serialization_traits<int> {
    static void serialize(std::ostream &os, int x) { os.write(reinterpret_cast<const char*>(&x), sizeof x); }
    static int deserialize(std::istream &is)       { int x; is.read(reinterpret_cast<char*>(&x), sizeof x); return x; }
};
template<> struct serialization_traits<std::size_t> {
    static void serialize(std::ostream &os, std::size_t x) { os.write(reinterpret_cast<const char*>(&x), sizeof x); }
    static int deserialize(std::istream &is)               { std::size_t x; is.read(reinterpret_cast<char*>(&x), sizeof x); return x; }
};

int main() {
    std::stringstream s;
    serialization_traits<std::size_t>::serialize(s, 10U);
    serialization_traits<int>::serialize(s, 20);
    assert(serialization_traits<std::size_t>::deserialize(s) == 10U);
    assert(serialization_traits<int>::deserialize(s) == 20);

    // serialization_traits<std::string>::serialize(s, "hi");  // compilation error: requests 'serialize' member
}
