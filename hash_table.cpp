#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashTable {
    private:
        int table_size = 10;
        vector<list<pair<int, int>>> table;

        int hash_function(int key) {
            return key % table_size;
        }

    public:
        HashTable() {
            table.resize(table_size);  // 把table的大小調整成table_size
        }

        void insert(int key, int value) {
            int index = hash_function(key);
            table[index].push_back({key, value});
            cout << "成功新增資料: key = " << key << " value = " << value << endl;
        }

        void search(int key) {
            int index = hash_function(key);

            for (auto pair : table[index]) {
                if (pair.first == key) {
                    cout << "成功搜尋資料: key = " << key << " value = " << pair.second << endl;
                    return;
                }
            }
            cout << "找不到資料: key = " << key << endl;
        }

        void update(int key, int new_value) {
            int index = hash_function(key);

            for (auto &pair : table[index]) {
                if (pair.first == key) {
                    int old_value = pair.second;
                    pair.second = new_value;
                    cout << "成功修改資料: key = " << key << ", value = " << old_value << " -> " << new_value << endl;
                    return;
                }
            }
            cout << "修改失敗，找不到 key = " << key << endl;
        }

        void remove(int key) {
            int index = hash_function(key);

            for (auto i = table[index].begin(); i != table[index].end(); i++) {
                if (i->first == key) {
                    table[index].erase(i);
                    cout << "成功刪除資料: key = " << key << endl;
                    return;
                }
            }
            cout << "找不到資料 key = " << key << endl;
        }

        void display() {
            for (int i = 0; i < table_size; i++) {
                cout << i << ": ";
                for (auto pair : table[i]) {
                    cout << "(" << pair.first << ", " << pair.second << ") ";
                }
                cout << endl;
            }
        }
};

int main() {
    HashTable hash_table;
    /*
        0:
        1: (1,100) (11,200)
        2: (22,300)
    ...
    */

    hash_table.insert(1, 100);  // (鍵, 值)
    hash_table.insert(11, 200);
    hash_table.insert(22, 300);

    hash_table.display();

    hash_table.search(11);
    hash_table.search(5);

    hash_table.update(11, 999);

    hash_table.remove(1);

    hash_table.display();

    return 0;
}