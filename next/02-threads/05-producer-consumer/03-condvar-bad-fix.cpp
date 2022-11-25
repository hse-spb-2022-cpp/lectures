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
            std::unique_lock l(m);
            std::cin >> input;  // input меняем только под мьютексом, иначе стреляет редко и метко.
            input_available = true;
            cond.notify_one();
        }  // мьютекс разблокирован очень-очень мало времени, не успеваем переключиться на consumer и схватить.
    });

    std::thread consumer([&]() {
        while (true) {
            std::unique_lock l(m);
            cond.wait(l, [&]() { return input_available; });
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
