#ifndef A_H_
#define A_H_

#include <string>

// `constexpr` means "initialize in compile-time", guarantees no problems with SIOF.

inline constexpr char str1[] = "Hello";  // The best.
// std::string is constexpr only since C++20
inline const std::string str2 = "World";  // Does not work in Visual Studio: https://abseil.io/tips/140#non-portable-mistake
constexpr char str3[] = "My";
const std::string str4 = "Dear";

struct Foo {
    static inline constexpr char str1[] = "1";
    static inline const std::string str2 = "2";
    static constexpr char str3[] = "3";  // Implies inline since C++17? I don't know.
    // static const std::string str4 = "4";
    static const std::string str4;
};

void foo();

#endif  // A_H_
