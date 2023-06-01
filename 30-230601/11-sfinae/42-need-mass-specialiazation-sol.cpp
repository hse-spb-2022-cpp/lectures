#include <cassert>
#include <iostream>
#include <sstream>
#include <string>

// See https://github.com/emscripten-core/emscripten/pull/9089

template<typename T, typename /* Dummy */ = void> struct serialization_traits {
    static void serialize(std::ostream &os, const T &x) {      x.serialize(os); }
    static T deserialize(std::istream &is)              { T x; x.deserialize(is); return x; }
};

// Specialize for serialization_traits<T, void> iff std::is_trivially_copyable_v<T>, SFINAE otherwise.
template<typename T> struct serialization_traits<T, std::enable_if_t<std::is_trivially_copyable_v<T>>> {
    static void serialize(std::ostream &os, const T &x) { os.write(reinterpret_cast<const char*>(&x), sizeof x); }
    static T deserialize(std::istream &is)              { T x; is.read(reinterpret_cast<char*>(&x), sizeof x); return x; }
};

int main() {
    std::stringstream s;
    serialization_traits<std::size_t>::serialize(s, 10U);
    serialization_traits<int>::serialize(s, 20);
    assert(serialization_traits<std::size_t>::deserialize(s) == 10U);
    assert(serialization_traits<int>::deserialize(s) == 20);

    // serialization_traits<std::string>::serialize(s, "hi");  // compilation error: requests 'serialize' member
}
