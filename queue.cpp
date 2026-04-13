#include <iostream>
#include <vector>
using namespace std;

struct Queue {
    private:
        vector<int> data;

    public:
        // 將元素加入佇列
        void enqueue(int value) {
            data.push_back(value);
        }

        // 查看頭端元素
        int front() {
            if (data.empty()) {
                throw out_of_range("佇列是空的");
            }
            return data.front();
        }

        // 移除頭端元素
        void dequeue() {
            if (data.empty()) {
                throw out_of_range("佇列是空的");
            }
            data.erase(data.begin());
        }

        // 取得佇列大小
        size_t size() const {
            return data.size();
        }
};

int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "目前頭端元素: " << queue.front() << endl;
    cout << "佇列大小: " << queue.size() << endl;

    queue.dequeue();
    cout << "目前頭端元素: " << queue.front() << endl;

    return 0;
}