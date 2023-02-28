#include <iostream>
#include <memory>

template<int X, bool SHOULD_THROW = false>
struct with_destructor {
    // If throws, object is dead, basic safety ~ strong safety.
    with_destructor(bool should_throw = false) {
        std::cout << "constructing " << X << " " << this << "\n";
        if (SHOULD_THROW || should_throw) {
            throw 0;
        }
    }
    ~with_destructor() {
        std::cout << "destructing " << X << " " << this << "\n";
    }
};

template<typename T1, typename T2, typename T3>
void foo(
    [[maybe_unused]] std::unique_ptr<T1> a,
    [[maybe_unused]] std::unique_ptr<T2> b,
    [[maybe_unused]] std::unique_ptr<T3> с
) {
    std::cout << "foo\n";
}

int main() {
     try {
         // OK only at and after C++17:
         foo(
             std::unique_ptr<with_destructor<1>>(new with_destructor<1>(false)),
             std::unique_ptr<with_destructor<2>>(new with_destructor<2>(true)),
             std::unique_ptr<with_destructor<3>>(new with_destructor<3>(false))
         );
         /*
         // Before C++17:
         1. new with_destructor<3>(false)
         2. new with_destructor<2>(true)
         3. new with_destructor<1>(false)
         4. unique_ptr(....)
         5. unique_ptr(....)
         6. unique_ptr(....)
         // Before C++17:
         1. make_unique<with_destructor<3>>(false)
         2. make_unique<with_destructor<2>>(true)
         3. make_unique<with_destructor<1>>(false)

         // https://herbsutter.com/gotw/_102/
         */
     } catch (...) {
         std::cout << "caught\n";
     }
}
