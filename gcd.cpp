#include <iostream>
using namespace std;

// 使用輾轉相除法計算最大公因數
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;  // 將a除以b的餘數賦值給b
        a = temp;   // 讓a等於b
    }
    return a;  // 當b為0時，a就是最大公因數
}

int main() {
    int a = 15;
    int b = 20;

    int result = gcd(a, b);
    
    cout << "最大公因數: " << result << endl;

    return 0;
}