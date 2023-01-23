#include <algorithm>
#include <utility>

template<typename T>
struct my_ptr {
private:
    T *data;

public:
    my_ptr/*<T>*/() : data(new T()) {}
    my_ptr(T value) : data(new T(std::move(value))) {}

    my_ptr(const my_ptr/*<T>*/ &other) : data(new T(*other->data)) {}
    my_ptr(my_ptr &&other) : data(std::exchange(other->data, new T())) {}

    my_ptr &operator=(const my_ptr &other) {
        *data = *other.data;
        return *this;
    }

    my_ptr &operator=(my_ptr &&other) {
        std::swap(data, other.data);
        return *this;
    }

    ~my_ptr() {
        delete data;
    }
};

int main() {
    my_ptr<int> x(10), y(12);
    my_ptr<double> z(10.5);
    x = y;
    // x = z;
}
