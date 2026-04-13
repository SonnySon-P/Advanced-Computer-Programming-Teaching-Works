#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    vector<int> dp = {0, 1};

    for (int i = 2; i <= n; i++) {
        dp.push_back(dp[i - 1] + dp[i - 2]);
    }

    return dp[n];
}

int main() {
    int result = fibonacci(7);

    cout << "費波那契數列: " << result << endl;

    return 0;
}