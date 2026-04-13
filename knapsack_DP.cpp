#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int>& weights, vector<int>& values, int capacity, int i) {
    int n = weights.size();
    int dp[100][100] = {0};  // dp[i][w] = 前i個物品，在容量w下的最大價值

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(
                    dp[i - 1][w],  // 不拿
                    dp[i - 1][w - weights[i - 1]] + values[i - 1]  // 拿，先騰出空間，再加上這個物品的價值
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int capacity = 7;
    vector<int> weights = {1, 3, 4, 5}; 
    vector<int> values  = {1, 4, 5, 7}; 

    cout << "最大價值: " << knapsack(weights, values, capacity, 0) << endl;

    return 0;
}