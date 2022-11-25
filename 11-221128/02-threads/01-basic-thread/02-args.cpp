#include <iostream>
#include <thread>

void worker(int a, int &b) {
    std::cout << "Thread: " << a << " " << &b << "\n";
}

int main() {
    int a = 10, b = 20;
    std::thread(worker, a, std::ref(b)).join();
}
