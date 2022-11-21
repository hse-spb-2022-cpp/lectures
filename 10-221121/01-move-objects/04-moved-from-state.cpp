#include <cassert>
#include <memory>
#include <string>
#include <vector>
#include <iostream>

int main() {
    {
        std::unique_ptr<int> ptr(new int(200));
        std::cout << ptr.get() << "\n";
        std::move(ptr);  // Does nothing.
        std::cout << ptr.get() << "\n";
        auto ptr2 = std::move(ptr);
        // Guaranteed: ptr.get() == nullptr
        std::cout << ptr2.get() << " " << ptr.get() << "\n";
    }
    {
        std::string s1 = "hello";
        std::string s2 = std::move(s1);
        // s1 is 'moved-from': valid, but unspecified.
        // May be empty, may be "hello", may be in a random state.
        std::cout << "|" << s1 << "| |" << s2 << "|\n";  // ok
        assert(s1.empty());  // FIXME: may fail
        s1 = "ok";  // ok

        /*
        // small string optimization (small object optimization)
        struct string {
            char buf_small[10];
            char *buf_big = nullptr;
            void move_from(string &other) {
                if (other.buf_big) {
                    buf_big = other.buf_big;
                    other.buf_big = nullptr;
                } else {
                    buf_small[0] = other.buf_small[0];
                    buf_small[1] = other.buf_small[1];
                    // ...
                    other.len = 0;  // optional
                }
            }
        };
        */
    }
}
