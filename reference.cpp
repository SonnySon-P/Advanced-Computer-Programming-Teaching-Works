#include <iostream>
using namespace std;

int main() {
    int number = 10;
    int& reference = number;  // 宣告參考，reference是number的別名

    cout << "Number的值: " << number << endl;
    cout << "Reference的值: " << reference << endl;

    reference = 30;  // 修改reference的值，number的值也會跟再改
    
    cout << "修改後的Number的值: " << number << endl;
    cout << "修改後的Reference的值: " << reference << endl;

    return 0;
}