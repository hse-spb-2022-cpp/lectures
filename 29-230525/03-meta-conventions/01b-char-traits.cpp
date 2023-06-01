#include <cctypes>

template<typename T>
struct char_traits {
    static bool eq(T a, T b) {
        return a == b;
    }
};

struct CaseInsensitiveChar { char c; }

template<>
struct char_traits<CaseInsensitiveChar> {
    static bool eq(T a, T b) {
        return tolower(a.c) == tolower(b.c);
    }
};

// Can also add static methods (`char_traits::eq`, `allocator_traits::allocate`) or static fields
// See https://stackoverflow.com/a/5319855/767632 for char_traits, but I've never seen it
// Typically no non-static methods.
