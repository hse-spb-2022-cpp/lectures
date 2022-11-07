#include <iostream>
#include <memory>
#include <utility>

struct Node {
    int value;
    std::unique_ptr<Node> next;

    Node(int value_, std::unique_ptr<Node> next_)
        : value(value_)
        , next(std::move(next_)) {
    }
};

int main() {
    auto a = std::make_unique<Node>(10, std::make_unique<Node>(20, nullptr));
    std::cout << a->value << " " << a->next->value << "\n";

    auto c = std::make_unique<Node>(30, std::move(a));
    std::cout << (a == nullptr) << "\n";
    std::cout << c->value << " " << c->next->value << "\n";
}
