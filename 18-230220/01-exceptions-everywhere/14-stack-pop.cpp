#include <vector>

template<typename T>
struct stack {
    std::vector<T> data;

    T pop() {
        T result = std::move(data.back());
        data.pop_back();
        return result;
    }
};

int main() {
    stack<int> s;
    s.data = std::vector{1, 2, 3, 4, 5};

    int x = 10;
    x = s.pop();  // If exception is thrown by `operator=`, `s` cannot restore stack state.
                  // Looks like strong guarantee violation.
}
