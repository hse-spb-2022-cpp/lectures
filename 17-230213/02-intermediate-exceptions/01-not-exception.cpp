int main() {
    int x = 2 * 2'000'000'000;  // UB
    int y = 2 / 0;  // UB
    assert(false);  // assertion failed, может быть удалён.

    std::vector<int> vec(10);  // Может быть std::bad_alloc, если памяти не хватило.
    vec[10] = 5;  // UB
    vec.at(10) = 5;  // std::out_of_bounds : std::exception, гарантируется.
}
