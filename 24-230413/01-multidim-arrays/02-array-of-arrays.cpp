#include <iostream>

void bar(int ***arr2) {
    std::cout << arr2[1][2][3] << "\n";
}

int main() {
    int arr[3][4][5]{};
    arr[1][2][3] = 123;
    std::cout << sizeof(arr) << "\n";

    // int ***arr2 = arr;  // Not the same!
    int ***arr2 = new int**[3];  // Extra memory for pointers
    for (int i = 0; i < 3; i++) {
        arr2[i] = new int*[4];  // More extra memory for pointers
        arr2[i][0] = new int[5]{};
        arr2[i][1] = new int[5]{};
        arr2[i][2] = new int[5]{};
        arr2[i][3] = new int[5]{};
    }
    arr2[1][2][3] = 123;

    /*
     int***         int**
    +------+     +---------+---------+---------+
    | arr2 | --> | arr2[0] | arr2[1] | arr2[2] |
    +------+     +----|----+---------+---------+
             +--------+
             v               int*
    +------------+------------+------------+------------+
    | arr2[0][0] | arr2[0][1] | arr2[0][2] | arr2[0][3] | (x3)
    +------|-----+-------|----+------------+------------+
           |             +-------+
           v   int               v    int
        +---+---+---+---+---+  +---+---+---+---+---+
        |000|001|002|003|004|  |010|011|012|013|014|  (x3 x4)
        +---+---+---+---+---+  +---+---+---+---+---+
    */
    std::cout << "=====\n";
    // Elements in the same "line" are consecutive
    std::cout << &arr2[0][0][0] << "\n";
    std::cout << &arr2[0][0][1] << "\n";
    std::cout << &arr2[0][0][2] << "\n";
    std::cout << &arr2[0][0][3] << "\n";
    std::cout << &arr2[0][0][4] << "\n";
    // Lines are independent
    std::cout << &arr2[0][1][0] << "\n";
    std::cout << &arr2[0][1][1] << "\n";
    bar(arr2);

    for (int i = 0; i < 3; i++) {
        delete[] arr2[i][0];
        delete[] arr2[i][1];
        delete[] arr2[i][2];
        delete[] arr2[i][3];
        delete[] arr2[i];
    }
    delete[] arr2;
}
