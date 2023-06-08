// Since C++20: conditional `explicit` is available as well
// Example: pair<T, U>() is implicit iff both T() and U() are implicit

// TODO
template<typename T, typename U>
struct pair {
     explicit(.....) pair() {}
}
