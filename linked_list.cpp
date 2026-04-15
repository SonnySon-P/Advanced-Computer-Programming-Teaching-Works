#include <iostream>
using namespace std;

class LinkedList {
    private:
        struct Node {
            int data;
            Node* next;
        };

        Node* head;  // 頭指標

    public:
        // 建構子
        LinkedList() {
            head = nullptr;
        }

        // 新增節點
        void insert(int value) {
            Node* new_node = new Node{value, nullptr};

            if (head == nullptr) {
                head = new_node;
            } else {
                Node* temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = new_node;
            }

            cout << "成功新增資料: " << value << endl;
        }

        // 搜尋節點
        Node* search(int target) {
            Node* temp = head;
            while (temp != nullptr) {
                if (temp->data == target) {
                    return temp;
                }
                temp = temp->next;
            }
            return nullptr;
        }

        // 修改節點
        void update(int old_value, int new_value) {
            Node* target_node = search(old_value);
            if (target_node != nullptr) {
                target_node->data = new_value;
                cout << "成功修改資料: " << old_value << " -> " << new_value << endl;
            } else {
                cout << "找不到資料: " << old_value << endl;
            }
        }

        // 刪除節點
        void remove(int target) {
            Node *temp = head;
            Node *previous = nullptr;

            // 假如第一筆資料就是target（因為刪除第一筆資料後，不需要串列傳後合併）
            if (temp != nullptr && temp->data == target) {
                head = temp->next;
                delete temp;
                cout << "成功刪除資料: " << target << endl;
                return;
            }

            // 從第二筆資料開始搜尋
            while (temp != nullptr && temp->data != target) {
                previous = temp;
                temp = temp->next;
            }

            if (temp == nullptr) {
                cout << "找不到資料: " << target << endl;
            } else {
                previous->next = temp->next;
                delete temp;
                cout << "成功刪除資料: " << target << endl;
            }

            return;
        }

        // 顯示串列
        void display() {
            cout << "串列內容: ";

            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->data << " -> ";
                temp = temp->next;
            }

            cout << "NULL" << endl;
        }
};

int main() {
    LinkedList l;

    l.insert(10);
    l.insert(20);
    l.insert(30);
    l.insert(40);
    l.display();

    int target = 20;
    if (l.search(20)) {
        cout << "成功搜尋資料: " << target << endl;
    } else {
        cout << "找不到資料: " << target << endl;
    }

    l.update(20, 99);
    l.display();

    l.remove(30);
    l.display();

    return 0;
}