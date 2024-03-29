#include <cstddef>
#include <utility>

// https://stackoverflow.com/a/123995/767632
template<typename T>
struct my_vector {
    T *data;

    const T &operator[](std::size_t i) const {
        // Possible:
        // if (i >= len) {
        //    throw ....;
        // }
        return *(data + i);
    }
    T &operator[](std::size_t i) {
        // OK: we know that `this` is actually non-const.
        return const_cast<T&>(std::as_const(*this)[i]);
    }
};


template<typename T>
struct my_vector_bad {
    T *data;

    T &operator[](std::size_t i) {
        return *(data + i);
    }
    const T &operator[](std::size_t i) const {
        // More dangerous: what if `this` is actually const and `operator[]` actually changes it?
        // Not UB? Not sure.
        return const_cast<my_vector_bad&>(*this)[i];
    }
};

int main() {}
