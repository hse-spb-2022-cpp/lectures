#include <cassert>
#include <string>
#include <iostream>

struct node_indexed {
    std::string data;
    int prev = -1, next = -1;
};

struct node_ptr {
    std::string data;
    node_ptr *prev = nullptr, *next = nullptr;  // Note that '*' is next to name
    // nullptr is better than NULL or 0.
};

int main() {
    {
        node_indexed nodes[3]{
            {"hello", /*prev*/ -1, /*next*/ 1},
            {"world", /*prev*/ 0, /*next*/ 2},
            {"wow", /*prev*/ 1, /*next*/ -1}
        };
        int head = 0;
        std::cout << nodes[head].data << "\n";  // hello
        std::cout << nodes[nodes[head].next].data << "\n";  // world
        std::cout << nodes[nodes[nodes[head].next].next].data << "\n";  // wow
    }
    std::cout << "\n";
    {
        node_ptr a{"hello"}, b{"world"}, c{"wow"};

        // Unlike reference:
        // 1. Can be nullptr.
        assert(a.prev == nullptr);
        assert(c.next == nullptr);
        // 2. Can be changed.
        a.next = &b; b.prev = &a;  // `&` means 'take address of'
        b.next = &c; c.prev = &b;

        // `*` means 'dereference', like with iterators
        std::cout <<   b      .data << "\n";  // world
        std::cout << (*a.next).data << "\n";  // world
        std::cout <<   a.next->data << "\n";  // world

        a.next = &c;
        std::cout << (*a.next).data << "\n";  // wow
        std::cout <<   a.next->data << "\n";  // wow

        *a.prev;  // UB: dereference of nullptr
        a.next++;  // Possible, 'pointer arithemtics' ~ 'iterators', out of scope for now
    }
}
