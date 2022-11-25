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
    std::cout << "Detaching...\n";
    t.detach();  // Обещаем больше не делать join(), теперь ОС отвечает за сборку мусора в потоке.
                 // Возникает только если нам вообще ничего от потока `t` никогда не будет нужно.
                 // Единственный разумный пример: мы создаём сетевой сервер, который в бесконечном цикле плодит потоки для клиентов.
    std::cout << "data is " << data << "\n";
    // После завершения main() завершается программа, но поток всё ещё работает — UB (обращения к умершим глобальным переменным).
    // Если используем pthread, то можем завершить main(), не завершая программу.
    return 0;
}
