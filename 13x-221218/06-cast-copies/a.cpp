int main() {
    double x = 1.5;
    int y = static_cast<int>(x);
    int &z = static_cast<int&>(x);  // CE
}
