#include <iostream>

struct node {
    node *prev = nullptr;
    node *next = nullptr;
};

struct node_with_data : node {
    int data;

    node_with_data(int data_) : data(data_) {}
};

void link(node &x, node &y) {
    x.next = &y;
    y.prev = &x;
}

int main() {
    node l;
    node_with_data a(10), b(20), c(30);

    link(l, a);
    link(a, b);
    link(b, c);
    link(c, l);

    for (node *it = l.next; it != &l; it = it->next) {
        auto it_data = static_cast<node_with_data*>(it);
        std::cout << it_data->data << "\n";
    }
    std::cout << "=====\n";

    node_with_data d(40);
    link(a, d);
    link(d, b);

    for (node *it = l.next; it != &l; it = it->next) {
        auto it_data = static_cast<node_with_data*>(it);
        std::cout << it_data->data << "\n";
    }
}
