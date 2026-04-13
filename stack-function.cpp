#include <iostream>
#include <vector>
using namespace std;

// 取得堆疊大小
size_t size(const vector<int>& data) {
    return data.size();
}

// 移除頂端元素
void pop(vector<int>& data) {
    if (data.empty()) {
        throw out_of_range("堆疊是空的，無法執行 pop");
    }
    data.pop_back();
}

// 查看頂端元素
int top(const vector<int>& data) {
    if (data.empty()) {
        throw out_of_range("堆疊是空的");
    }

    return data.back();
}

// 將元素推入堆疊
void push(vector<int>& data, int value) {
    data.push_back(value);
}

int main() {
    vector<int> stack;  // 用vector當堆疊

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    cout << "目前頂端元素: " << top(stack) << endl;
    cout << "堆疊大小: " << size(stack) << endl;

    pop(stack);

    cout << "目前頂端元素: " << top(stack) << endl;

    return 0;
}