#include <cassert>
#include <tuple>
#include <string>

using std::string;

std::tuple<int, string> foo() {
    return {30, "baz"};
}

int main() {
    {
        int a = 10; string b = "foo";
        std::tuple<int&, string&&> t(a, std::move(b));  // can store arbitrary references
        t = std::make_tuple(20, "bar");  // assigns to every field
        assert(a == 20);
        assert(b == "bar");

        std::tie(a, b) = foo();  // creates a temporary tuple<int&, string&>
        assert(a == 30);
        assert(b == "baz");
    }
}
