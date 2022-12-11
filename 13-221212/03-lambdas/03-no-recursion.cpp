#include <functional>

int main() {
    {
        auto fib = [&](int n) {
            if (n <= 1) return n;
            // Compilation error: type of lambda depends on its captures => cannot capture fib.
            return fib(n - 1) + fib(n - 2);
        };
    }
    {
        std::function<int(int)> fib = [&](int n) {
            if (n <= 1) return n;
            // Careful: calls to virtual functions!
            return fib(n - 1) + fib(n - 2);
        };
    }
    {
        struct Fib {
            int operator()(int n) {
                if (n <= 1) return n;
                return operator()(n - 1) + operator()(n - 2);
                // return (*this)(n - 1) + (*this)(n - 2);
            }
        } fib;
    }
}
