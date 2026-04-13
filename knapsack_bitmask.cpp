#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    int max_value = 0;

    for (int mask = 0; mask < (1 << n); ++mask) {
        int total_weight = 0;
        int total_value = 0;

        for (int i = 0; i < n; ++i) {
            // 檢查mask的第i個位元是否為1
            if ((mask >> i) & 1) {
                total_weight += weights[i];
                total_value += values[i];
            }
        }

        // 如果總重量在負荷內，更新最大價值
        if (total_weight <= capacity) {
            max_value = max(max_value, total_value);
        }
    }

    return max_value;
}

int main() {
    int capacity = 7;
    vector<int> weights = {1, 3, 4, 5}; 
    vector<int> values  = {1, 4, 5, 7}; 

    cout << "最大價值: " << knapsack(weights, values, capacity) << endl;

    return 0;
}