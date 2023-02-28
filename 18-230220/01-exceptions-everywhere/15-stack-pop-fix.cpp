#include <vector>

template<typename T>
struct stack {
    std::vector<T> data;

    void pop_into(T &result) {
        result = std::move(data.back());
        data.pop_back();
    }
};

int main() {
    stack<int> s;
    s.data = std::vector{1, 2, 3, 4, 5};

    int x = 10;
    s.pop_into(x);  // All exceptions are handled by `pop` itself.
}
