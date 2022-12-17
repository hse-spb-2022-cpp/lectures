#include <cassert>
#include <iostream>
#include <utility>

struct Foo {
    int member_var = 10;
    static inline int static_member_var = 20;
    int arr[10'000];

    void method() {
        int local_var = 30;
        static int static_local_var = 40;
        [[maybe_unused]] long long local_big[100]{};

        // 1
        auto lambda1 = []() {
            // Not captured.
            // [[maybe_unused]] int x = member_var;
            // [[maybe_unused]] int y = local_var;
            // Never captured, always available.
            static_member_var++;
            static_local_var++;
        };
        lambda1();
        std::cout << "sizeof(lambda1) == " << sizeof(lambda1) << "\n";
        assert(static_member_var == 21);
        assert(static_local_var == 41);

        // 2
        std::cout << "before lambda 2: " << &member_var << " " << &local_var << "\n";
        auto lambda2 = [=]() {  // [this, local_var]
            std::cout << "in lambda 2    : " << &member_var << " " << &local_var << "\n";
            assert(member_var == 10); // this->member_var: reference!
            assert(local_var == 30);
            // assert(local_big[0] == 0);  // Not captured, as unused.
            // operator() is const by default.
            member_var++;  // this is const, but *this is not.
            // local_var++;
        };
        local_var++;  // Do not affect lambda2().
        lambda2();
        local_var--;
        std::cout << "sizeof(lambda2) == " << sizeof(lambda2) << "\n";

        // 3
        auto lambda3 = [=]() mutable {  // [this, local_var]
            // operator() is non-const now.
            member_var++;
            local_var++;
            std::cout << "in lambda 3: local_var new = " << local_var << "\n";
        };
        lambda3();
        lambda3();
        std::cout << "sizeof(lamda3) == " << sizeof(lambda3) << "\n";
        assert(member_var == 13);  // Changed.
        assert(local_var == 30);  // Unchanged.

        // 4
        [&]() {  // [this, &local_var]
            // operator() is still const, but these two work.
            member_var++;  // this->member_var, this is const.
            local_var++;  // local_var is a reference, the reference itself is always const.
        }();
        assert(member_var == 14);
        assert(local_var == 31);

        // 5
        std::cout << "before lambda 5: " << &member_var << " " << &local_var << "\n";
        auto lambda5 = [=, *this]() mutable {  // C++17: [*this, local_var]: full copy of '*this', including unused 'arr'.
            std::cout << "in lambda 5    : " << &member_var << " " << &local_var << "\n";
            assert(member_var == 14); // 'this' is fully copied.
            assert(local_var == 31);
            member_var++;
            local_var++;
        };
        lambda5();
        std::cout << "sizeof(lambda5) == " << sizeof(lambda5) << "\n";
        assert(member_var == 14);  // Unchanged.
        assert(local_var == 31);  // Unchanged.

        // 6
        [wtf = local_var + member_var]() {  // C++14
            assert(wtf == 45);
        }();
        [local_var = local_var * 2]() {
            assert(local_var == 62);
        }();
        assert(local_var == 31);

        // 7
        [&lvar = local_var]() {
            assert(lvar == 31);
            lvar++;
        }();
        assert(local_var == 32);
        [&local_var = std::as_const(local_var)]() {
            assert(local_var == 32);
            // local_var++;  // const int &local_var;
        }();
        assert(local_var == 32);
    }
};

int main() {
    static Foo foo;
    foo.method();
}
