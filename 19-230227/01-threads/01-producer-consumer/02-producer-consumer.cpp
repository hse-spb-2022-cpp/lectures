#include <chrono>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

int main() {
    std::mutex m;
    std::string input;
    bool input_available = false;

    std::thread producer([&]() {
        while (true) {
            std::cin >> input;

            std::unique_lock l(m);
            input_available = true;
        }
    });

    std::thread consumer([&]() {
        while (true) {
            std::string input_snapshot;
            {
                std::unique_lock l(m);
                if (!input_available) {
                    continue;
                }
                input_snapshot = input;  // Не хотим, чтобы input изменился, пока мы ждём две секунды.
                input_available = false;
            }  // l.unlock();

            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            std::cout << "Got string: " << input_snapshot << "\n";
        }
    });

    consumer.join();
    producer.join();
}
