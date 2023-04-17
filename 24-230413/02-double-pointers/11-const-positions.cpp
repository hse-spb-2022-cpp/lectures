#include <iostream>
#include <type_traits>

int main() {
    int x[10]{};
    const int cx[10]{};

    static_assert(std::is_same_v<int *, decltype(&x[0])>);
    {
        int *px = &x[0];  // not &cx[0]
        px++;
        px--;
        std::cout << *px << "\n";
        *px = 10;
        px = nullptr;
    }
    {
        const int *px = &cx[0];  // or &x[0]
        px++;
        px--;
        std::cout << *px << "\n";
        // *px = 10;
        px = nullptr;
    }
    {
        int *const px = &x[0];  // not &cx[0]
        // px++;
        // px--;
        std::cout << *px << "\n";
        *px = 10;
        // px = nullptr;
    }
    {
        [[maybe_unused]] const int *const px = &cx[0];  // or &x[0]
        // px++;
        // px--;
        std::cout << *px << "\n";
        // *px = 10;
        // px = nullptr;
    }

    {
        [[maybe_unused]] int *px = &x[0];  // not &cx[0]
        [[maybe_unused]] int *const cpx = px;
        [[maybe_unused]] const int *pcx = px;
        [[maybe_unused]] const int *const cpcx = px;
    }
    {
        const int a = 10;
        [[maybe_unused]] int b = a;

        [[maybe_unused]] int *const cpx = &x[0];
        [[maybe_unused]] int *px = cpx;
        [[maybe_unused]] const int *pcx = cpx;
        [[maybe_unused]] const int *const cpcx = cpx;
    }
    {
        [[maybe_unused]] const int *pcx = &cx[0];
        // [[maybe_unused]] int *px = pcx;
        // [[maybe_unused]] int *const cpx = pcx;
        [[maybe_unused]] const int *const cpcx = pcx;
    }
    {
        [[maybe_unused]] const int *const cpcx = &cx[0];
        // [[maybe_unused]] int *px = cpcx;
        // [[maybe_unused]] int *const cpx = cpcx;
        [[maybe_unused]] const int *pcx = cpcx;
    }

    {
        int *px = &x[0];
        [[maybe_unused]] int *py = &x[1];

        [[maybe_unused]] const int *const *const cpcpcx = &px;
        // cpcpcx = py;
        // *cpcpcx = &x[2];
        // **cpcpcx = 10;
    }
}
