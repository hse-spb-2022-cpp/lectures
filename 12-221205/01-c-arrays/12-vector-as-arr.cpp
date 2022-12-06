#include <iostream>
#include <vector>

void print_all(int *beg, int *en) {
    // Just like iterators
    for (int *it = beg; it != en; it++) {
        std::cout << *it << "\n";
    }
}

int main() {
    std::vector<int> vec(10);
    print_all(&vec[0], &vec[0] + vec.size());
    print_all(&*vec.begin(), &*vec.begin() + vec.size());
    print_all(vec.data(), vec.data() + vec.size());

    std::set<int> s{1, 2, 3};
    // UB:
    print_all(&*s.begin(), &*s.begin() + 3);
    int *s_it1 = &*s.begin();
    s_it2++;  // UB

    std::set<int>::iterator it_2 = s.begin();
    it_2++;  // ok
}
