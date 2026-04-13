#include <iostream>
#include <vector>
using namespace std;

// 定義堆疊物件
struct Stack {
    private:  
        vector<int> data;  // 定義堆疊結構

    public:
        // 將元素推入堆疊
        void push(int value) {
            data.push_back(value);
        }

        // 查看頂端元素
        int top() {
            if (data.empty()) {
                throw out_of_range("堆疊是空的");
            }
            
            return data.back();
        }

        // 移除頂端元素
        void pop() {
            if (data.empty()) {
                throw out_of_range("堆疊是空的");
            }

            data.pop_back();
        }

        // 取得堆疊大小
        size_t size() {
            return data.size();
        }
};

int main() {
    Stack stack;  // 建立堆疊物件

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "目前頂端元素: " << stack.top() << endl;
    cout << "堆疊大小: " << stack.size() << endl;

    stack.pop();

    cout << "目前頂端元素: " << stack.top() << endl;

    return 0;
}