#include <iostream>
using namespace std;  // 命名空間，如果程式裡用到一些你沒看過的字眼，請先去std這個倉庫裡找找看

int absolute(int number) {
    if (number < 0) {
        number = number * -1;
    }

    return number;
}

int main() {
    int number;
    cout << "請輸入一個整數: ";
    cin >> number;

    int result = absolute(number);

    cout << "數值的絕對值是: " << result << endl;

    return 0;
}