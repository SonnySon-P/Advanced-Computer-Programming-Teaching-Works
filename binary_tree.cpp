#include <iostream>
using namespace std;

class BinaryTree {
    private:
        struct Node {
            int data;
            Node* left;
            Node* right;
        };

        Node* root;

    public:
        BinaryTree() {
            root = nullptr;
        }

        Node* insert(Node* node, int value) {
            if (node == nullptr) {
                cout << "成功新增資料: " << value << endl;
                return new Node{value, nullptr, nullptr};
            }

            if (value < node->data)
                node->left = insert(node->left, value);
            else
                node->right = insert(node->right, value);

            return node;
        }

        Node* search(Node* node, int target) {
            if (node == nullptr || node->data == target)
                return node;

            if (target < node->data)
                return search(node->left, target);
            else
                return search(node->right, target);
        }

        Node* find_min_value(Node* node) {
            while (node->left != nullptr)
                node = node->left;
            return node;
        }

        Node* remove(Node* node, int target) {
            if (node == nullptr) {
                return nullptr;
            }

            if (target < node->data) {
                node->left = remove(node->left, target);
            } else if (target > node->data) {
                node->right = remove(node->right, target);
            } else {
                if (node->left == nullptr) {
                    Node* temp = node->right;
                    delete node;
                    return temp;
                } else if (node->right == nullptr) {
                    Node* temp = node->left;
                    delete node;
                    return temp;
                }

                Node* temp = find_min_value(node->right);
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }
            return node;
        }

        void inorder(Node* node) {
            if (node != nullptr) {
                inorder(node->left);
                cout << node->data << " ";
                inorder(node->right);
            }
        }

        void insert(int value) {
            root = insert(root, value);
        }

        Node* search(int target) {
            return search(root, target);
        }

        void update(int old_value, int new_value) {
            Node* node = search(old_value);
            if (node != nullptr) {
                remove(old_value);
                insert(new_value);
                cout << "成功修改資料: " << old_value << " -> " << new_value << endl;
            } else {
                cout << "找不到資料: " << old_value << endl;
            }
        }

        void remove(int target) {
            if (search(target) != nullptr) {
                root = remove(root, target);
                cout << "成功刪除資料: " << target << endl;
            } else {
                cout << "找不到資料: " << target << endl;
            }
        }

        void display() {
            cout << "中序遍歷: ";
            inorder(root);
            cout << endl;
        }
};

int main() {
    BinaryTree t;

    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(15);
    t.insert(30);
    t.display();

    int target = 20;
    if (t.search(target)) {
        cout << "成功搜尋資料: " << target << endl;
    } else {
        cout << "找不到資料: " << target << endl;
    }

    t.update(20, 99);
    t.display();

    t.remove(10);
    t.display();

    return 0;
}

/*
        10
       /  \
      5    20
          /  \
        15    30

        10
       /  \
      5    30
          /  \
        15    99

        15
       /  \
      5    30
              \
               99
*/