#include <deque>
#include <iostream>
#include <vector>
#include <set>

int main() {
    {
        std::set<int> s{10};
        const int &x = *s.begin();
        std::set<int>::iterator x_it = s.begin();
        s.insert(5);
        s.insert(15);
        std::cout << x << " " << *x_it << "\n";  // No invalidation
        s.erase(10);
        // x and x_it are invalid.
    }
    {
        std::cout << "vector\n";
        std::vector<int> vec{10, 20};
        int &x = vec[0];
        std::vector<int>::iterator x_it = vec.begin();
        vec[1] = 100;
        std::cout << &x << " " << &vec[0] << "\n";
        vec.pop_back();
        // If reallocated, all references and iterators are invalid
        vec.push_back(20);
        vec.push_back(30);
        vec.push_back(40);
        std::cout << &x << " " << &vec[0] << "\n";
        std::cout << x << " " << *x_it << "\n";
    }
    {
        std::cout << "vector erase\n";
        std::vector<int> vec{10, 20, 30};
        int &x = vec[1];
        vec.erase(vec.begin() + 1);
        // vec[1] = vec[2]; vec.pop_back();
        std::cout << x << "\n";
    }
    {
        std::deque<int> d{10};
        int &x = *d.begin();
        std::deque<int>::iterator x_it = d.begin();
        // Invalidates all iterators, but not references, e.g. in clang++ with Microsoft STL
        for (int i = 0; i < 1000; i++) {
            d.push_back(0);
            d.push_front(0);
        }
        std::cout << x << " " << *x_it << "\n";
    }
}
