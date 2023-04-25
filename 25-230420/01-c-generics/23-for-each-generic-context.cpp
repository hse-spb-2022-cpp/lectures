#include <cstddef>
#include <iostream>
#include <string>

void for_each(
        const void *begin,
        const void *end,
        std::size_t elem_size,
        void (*f)(void *, const void*),
        void *farg
) {
    for (; begin != end; begin = static_cast<const char*>(begin) + elem_size) {
        f(farg, begin);  // Can only pass element by pointer
    }
}

struct print_int_args {
    std::string name;
    int id;
};

void print_int(void *args_void, const void *x_void) {
    auto &args = *static_cast<print_int_args*>(args_void);
    const int &x = *static_cast<const int*>(x_void);

    std::cout << "print(" << args.name << ", id=" << args.id << ", " << x << ")\n";
}

int main(void) {
    int arr[10]{};
    arr[3] = 100;
    arr[5] = 200;

    print_int_args args;
    args.name = "printer";
    args.id = 123;
    for_each(arr, arr + 10, sizeof(arr[0]), print_int, &args);
}
