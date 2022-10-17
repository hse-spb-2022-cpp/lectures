// https://notes.algoprog.ru/cpp/additional.html#id4

#include <iostream>

using namespace std;

int a = 0;

int next_a() {
    a++;
    return a;
}

int subtract(int x, int y) {
    return x - y;
}

int main() {
    cout << next_a() << next_a() << endl;  // Может вывести как 12, так и 21.
    cout << subtract(next_a(), next_a()) << endl;  // Может вывести как 3-4 == -1, так 4-3 == 1.
    cout << subtract(next_a(), next_a()) << ' ' << next_a() << endl;  // Есть шесть вариантов выполнения.
    cout << 1 - 2 - 3 << endl;
    cout << (1 - 2) - 3 << endl;
    return 0;
}
