#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

int main() {
    std::mutex m;
    std::string input;
    bool input_available = false;
    std::condition_variable cond;

    std::thread producer([&]() {
        while (true) {
            std::cin >> input;
            std::unique_lock l(m);
            input_available = true;
            cond.notify_one();  // Разбудит один случайный поток. Важно, чтобы это было ему по делу.
        }
    });

    std::thread consumer([&]() {
        while (true) {
            std::unique_lock l(m);
            while (!input_available) {  // while, не if!
                cond.wait(l);
            }
            // Эквивалентная while конструкция, чтобы было сложнее набагать и были понятнее намерения.
            // cond.wait(l, []() { return input_available; });  // "ждём выполнения предиката".
            std::string input_snapshot = input;
            input_available = false;
            l.unlock();

            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            std::cout << "Got string: " << input_snapshot << "\n";
        }
    });

    consumer.join();
    producer.join();
}
