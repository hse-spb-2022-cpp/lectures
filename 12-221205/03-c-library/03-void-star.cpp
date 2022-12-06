#include <cassert>

// "Library"
void *user_data;

//todo: like setopt
void set_data(void *data) {
    user_data = data;
}

void *get_data() {
    return user_data;
}

// Somewhat like std::any

// Application
int main() {
    int data[]{1, 2, 3, 4};

    set_data(data);  // implicit: int[4] --> int* --> void*
    int *data_ptr = static_cast<int*>(get_data());
    assert(data_ptr[2] == 3);
}
