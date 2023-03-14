#include <iostream>
#include <memory>
#include <optional>
#include <utility>

std::optional<std::unique_ptr<int>> foo() {
    return std::make_unique<int>(10);
}

void just_print(const std::unique_ptr<int> &a) {
    if (a) {
        std::cout << "printed " << *a << std::endl;
    } else {
        std::cout << "printed nullptr" << std::endl;
    }
}

void consume_print(std::unique_ptr<int> a) {
    just_print(a);
}

int main() {
     // Own code
     struct Foo {
         std::unique_ptr<int> p = std::make_unique<int>(30);
         std::unique_ptr<int> &value() & {  // ref-qualifier  https://habr.com/ru/post/216783/
             return p;
         }
         const std::unique_ptr<int> &value() const& {
             return p;
         }
         std::unique_ptr<int> &&value() && {
             return std::move(p);
         }
     };

     Foo f;
     just_print(f.value());
     just_print(std::as_const(f).value());
     // consume_print(f.value()); // CE
     consume_print(std::move(f).value());
}
