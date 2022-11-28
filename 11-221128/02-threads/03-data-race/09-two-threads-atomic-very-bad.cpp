#include <atomic>
#include <iostream>
#include <thread>

struct list_node {
    std::atomic<int> value = 0;
    std::atomic<list_node*> next = nullptr;
};

void insert_after(list_node *n, int new_value) {
    list_node *n2 = new list_node;
    n2->value = new_value;

    #if 0
    n2->next = n->next;
    #else
    list_node *n_next = n->next;
    n2->next = n_next;
    #endif

    n->next = n2;

    // Further reading:
    // 1. Lock-free single linked list.
    // 2. CAS operations
    // 3. ABA problem
}

int main() {
    list_node head;
    const int N = 1'000'000;
    auto worker = [&]() {
        for (int i = 0; i < N; i++) {
            insert_after(&head, i);
        }
    };
    std::thread t1(worker);
    std::thread t2(worker);
    t1.join();
    t2.join();
    int len = 0;
    for (list_node *p = &head; p; p = p->next)
        len++;
    std::cout << len << "\n";
}
