#include <memory>
#include <list>
#include <vector>
#include <iostream>

// 'Static'/'compile-time' polymorphism
template<typename C>
bool is_empty(const C &c) {
    return c.empty();  // Which .empty() to call is determined in compile time
}

// 'Dynamic'/'run-time' polymorphism
struct AbstractContainer { virtual bool empty() = 0; };
struct VectorInt : AbstractContainer {
    std::vector<int> vec;
    bool empty() override {
        return vec.empty();
    };
};
struct ListInt : AbstractContainer {
    std::list<int> lst;
    bool empty() override {
        return lst.empty();
    };
};

bool is_empty(AbstractContainer &c) {
    return c.empty();  // Which .foo() to call is determined in run time
}

std::unique_ptr<AbstractContainer> create_container() {
    int type;
    std::cin >> type;
    if (type == 0) {
        return std::make_unique<VectorInt>();
    } else {
        return std::make_unique<ListInt>();
    }
}

int main() {
    std::vector<int> vec;
    std::list<int> lst;
    // vec's and lst's types are known
    std::cout << is_empty(vec) << "\n";
    std::cout << is_empty(lst) << "\n";

    std::unique_ptr<AbstractContainer> cont = create_container();
    // `cont` can be anything depending on create_container()
    std::cout << is_empty(*cont) << "\n";
}
