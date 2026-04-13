#include <iostream>
#include <vector>
using namespace std;

vector<int> path;        // 當前排列
bool used[100] = {false}; // 記錄是否使用過

void backtrack(vector<int>& numbers) {
    // 終止條件，長度等於numbers
    if (path.size() == numbers.size()) {
        for (int x : path) {
            cout << x << " ";
        }
        cout << endl;
        return;
    }

    // 嘗試每個元素
    for (int i = 0; i < numbers.size(); i++) {
        if (used[i]) continue; // 已用過就跳過

        // 選擇
        used[i] = true;
        path.push_back(numbers[i]);

        // 遞迴
        backtrack(numbers);

        // 回朔（撤銷選擇）
        path.pop_back();
        used[i] = false;
    }
}

int main() {
    vector<int> numbers = {1, 2, 3};

    cout << "所有排列:\n";
    backtrack(numbers);

    return 0;
}