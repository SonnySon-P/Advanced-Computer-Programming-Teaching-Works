#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int start, vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false);  // 紀錄旅行過的節點
    queue<int> queue;

    visited[start] = true;
    queue.push(start);

    int count = 0;  // 紀錄已輸出的節點數
    int number_of_nodes = graph.size(); 

    while (!queue.empty()) {
        int node = queue.front();
        queue.pop();
        count++;

        cout << node;

        if (count < number_of_nodes) {  // 如果這不是最後一個輸出的節點，就印出箭頭
            cout << " → ";
        } else {
            cout << endl;
        }
        
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push(neighbor);
            }
        }
    }
}

int main() {
    // 建立圖
    vector<vector<int>> graph = {{1, 2}, {0, 3, 4}, {0, 5}, {1}, {1, 5}, {2, 4}};  // graph[0] = {1, 2}，代表節點0連接到節點1與節點2

    cout << "BFS搜尋: ";
    BFS(0, graph);  // 參數1是起始點，參數2是圖

    return 0;
}