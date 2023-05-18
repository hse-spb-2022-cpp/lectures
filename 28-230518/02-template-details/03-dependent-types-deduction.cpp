#include <cassert>
#include <vector>

template<typename C>
bool is_begin(typename C::iterator it, const C &c) {  // If C is known, C::iterator is also known, even though it's on the right.
    return c.begin() == it;
}

template<typename C>
bool is_begin2(typename C::iterator) {  // Impossibe to deduce C from 'C::iterator'.
    return true;
}

struct not_vector { using iterator = typename std::vector<int>::iterator; };

int main() {
    std::vector<int> vec;
    assert(is_begin<std::vector<int>>(vec.end(), vec));
    assert(is_begin<>(vec.end(), vec));
    assert(is_begin(vec.end(), vec));

    is_begin2<std::vector<int>>(vec.begin());
    // is_begin2<>(vec.begin());  // compilation error: template argument deduction/substitution failed
    // is_begin2(vec.begin());  // compilation error: template argument deduction/substitution failed
}
