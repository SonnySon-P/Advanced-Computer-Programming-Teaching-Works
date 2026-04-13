#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> coins = {1000, 500, 100, 50, 10, 5, 1};  // 面額要由大排到小，假設各面額儲量足夠
    int amount;

    cout << "請輸入找零金額: ";
    cin >> amount;

    cout << "找零結果:\n";

    // 每次都選目前能用的最大面額
    for (int i = 0; i < coins.size(); i++) {
        if (amount >= coins[i]) {
            int count = amount / coins[i];  // 輪到使用面額可以用幾個
            
            amount %= coins[i];  // 剩下多少

            cout << coins[i] << " 元: " << count << " 個" << endl;
        }
    }

    return 0;
}