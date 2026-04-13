#include <iostream>
using namespace std;

int main() {
    int number = 10;  // 宣告整數變數
    int* pointer = &number;  // 宣告指標，並指向number的記憶體地址

    cout << "number的值: " << number << endl;
    cout << "number的記憶體地址: " << pointer << endl;
    cout << "pointer指向的值: " << *pointer << endl;  // 使用*來取得指標指向的值

    *pointer = 20;  // 修改指標所指向的值
    cout << "修改後的number的值: " << number << endl;

    return 0;
}