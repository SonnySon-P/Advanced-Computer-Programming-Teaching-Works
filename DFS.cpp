#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<vector<int>>& graph, vector<bool>& visited, int count, int number_of_nodes) {
    visited[node] = true;

    count++;

    cout << node;

    if (count < number_of_nodes) {
        cout << " → ";
    } else {
        cout << endl;
    }

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, graph, visited, count++, number_of_nodes);
        }
    }
}

int main() {
    vector<vector<int>> graph = {{1, 2}, {0, 3, 4}, {0, 5}, {1}, {1, 5}, {2, 4}};

    vector<bool> visited(graph.size(), false);
    int count = 0;
    int number_of_nodes = graph.size(); 

    cout << "DFS搜尋: ";
    DFS(0, graph, visited, count, number_of_nodes);  // 參數1是起始點，參數2是圖，參數3是紀錄旅行過的節點

    return 0;
}