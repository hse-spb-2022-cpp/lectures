#include <array>
#include <stdexcept>
#include <utility>

template<size_t N>  // Лучше не const char*, чтобы сразу знать размер.
constexpr auto parse_format(const char (&s)[N]) {
    int specifiers = 0;
    std::array<char, N> found{};
    for (size_t i = 0; i < N; i++) {  // strlen не constexpr
        if (s[i] == '%') {
            if (i + 1 >= N)
                throw std::logic_error("Expected specifier after %");
            i++;
            found[specifiers++] = s[i];
            if (!(s[i] == 'd' || s[i] == 'c' || s[i] == 's'))
                throw std::logic_error("Unknown specifier");
        }
    }
    return std::pair{specifiers, found};
}
static_assert(parse_format("hello%d=%s").first == 2);
static_assert(parse_format("hello%d=%s").second[0] == 'd');
static_assert(parse_format("hello%d=%s").second[1] == 's');
// static_assert(parse_format("hello%d=%").second[1] == 's');

// !! NOT FOR EXAM DOWN BELOW !!

// Hard level:
// https://github.com/hanickadot/compile-time-regular-expressions

// Harder level: https://github.com/fmtlib/fmt
// Before C++20: at least one non-constexpr argument => function is non-constexpr, so format("%d%d", x) cannot check the format.
//               Workaround: format(parse_format("%d%d"), x), the `parse_format` function creates an object whose type encodes the format.
// Since C++20: https://godbolt.org/z/ao4WxK7bv

int main() {}
