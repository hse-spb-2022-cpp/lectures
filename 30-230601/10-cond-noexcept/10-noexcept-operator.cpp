#include <cassert>
#include <vector>

int foo() noexcept { return 1; }
int bar()          { return 2; }
std::vector<int> get_vec() noexcept { return {}; }

int main() {
    int a = 10;
    std::vector<int> b;
    // Simple cases
    static_assert(noexcept(a == 10));
    static_assert(!noexcept(new int{}));   // no leak: not computed
    static_assert(noexcept(a == foo()));
    static_assert(!noexcept(b == b));      // vector::operator== is not noexcept for some reason, but I don't know how it can fail
    bool x = noexcept(a == 20);
    assert(x);

    // Complex expressions
    static_assert(!noexcept(a == bar()));  // bar() is not noexcept
    static_assert(noexcept(get_vec()));  // noexcept even though copying vector may throw: return value creation is considered "inside" function
    static_assert(noexcept(b = get_vec()));  // operator=(vector&&) does not throw
    static_assert(!noexcept(b = static_cast<const std::vector<int>&>(get_vec())));  // operator=(conts vector&) throws
}
