#include <iostream>
using namespace std;

// 遞迴函數，用來計算從1到n的累加和
int sum(int n) {
    if (n == 1) {  // 基本情況：當n為1時，返回1
        return 1;
    }
    return n + sum(n - 1);  // n加上從1到n-1的累加
}

int main() {
    int result = sum(100);

    cout << "1到100的累加和是: " << result << endl;

    return 0;
}