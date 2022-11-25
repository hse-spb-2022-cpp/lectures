#include <chrono>
#include <iostream>
#include <thread>

int main() {
    int data = 1234;
    std::thread t([&]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "Hello from thread! data=" << data << "\n";
        data += 10;
    });
    std::cout << "Waiting for it...\n";
    t.join();  // Освобождает ресурсы потока.
    std::cout << "data is " << data << "\n";
    // Вызывается ~thread(), к этому моменту обязательно сделать join().
    return 0;
}
