#include <iostream>
using namespace std;

// Compile-time Polymorphism
void print(int a) {
    cout << "整數: " << a << endl;
}

void print(double a) {
    cout << "浮點數: " << a << endl;
}

void print(int a, double b) {
    cout << "整數: " << a << ", 浮點數: " << b << endl;
}

int main() {
    print(5);  // 呼叫print(int)
    print(3.14);  // 呼叫print(double)
    print(10, 3.14);  // 呼叫print(int, double)

    return 0;
}