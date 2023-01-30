#include <memory>

int ints[10'000];
int free_int = 0;

int *my_alloc() {
    int *result = &ints[free_int];
    free_int++;
    return result;
}

void my_dealloc(int *x) {
    if (x == &ints[free_int - 1]) {
        free_int--;
    }
}

struct MyDeleter {
    void operator()(int *x) {
        my_dealloc(x);
    }
};

int main() {
    [[maybe_unused]] std::unique_ptr<int> x(new int(10));  // by default call `delete`
    // std::unique_ptr<int> y(my_alloc());  // calls `delete`, UB
    std::unique_ptr<int, MyDeleter> z(my_alloc());  // calls operator()

    // For deleter with state: see test `TEST_CASE("unique_ptr custom copyable deleter")` from public tests
}
