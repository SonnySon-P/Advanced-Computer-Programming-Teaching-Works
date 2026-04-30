#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void MST(int start, vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();

    vector<int> key(n, INT_MAX);  // 類似dijkstra distance，但代表接入MST的最小權重
    vector<bool> inMST(n, false);   // 是否已加入MST，類似dijkstra程式中的visited
    vector<int> parent(n, -1);

    key[start] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;
        int min_key = INT_MAX;

        // 找目前不在MST中key最小的點
        for (int j = 0; j < n; j++) {
            if (!inMST[j] && key[j] < min_key) {
                min_key = key[j];
                u = j;
            }
        }

        if (u == -1) {
            break;
        }

        inMST[u] = true;

        // 更新鄰居
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
            }
        }
    }

    // 輸出結果
    cout << "最小生成樹:\n";
    int total_weight = 0;

    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " → " << i << " (weight: " << key[i] << ")\n";
            total_weight += key[i];
        }
    }

    cout << "總權重: " << total_weight << endl;
}

int main() {
    int number_of_nodes = 6;

    vector<vector<pair<int, int>>> graph(number_of_nodes);
    graph[0] = {{1, 7}, {2, 9}, {5, 14}};
    graph[1] = {{0, 7}, {2, 10}, {3, 15}};
    graph[2] = {{0, 9}, {1, 10}, {3, 11}, {5, 2}};
    graph[3] = {{1, 15}, {2, 11}, {4, 6}};
    graph[4] = {{3, 6}, {5, 9}};
    graph[5] = {{0, 14}, {2, 2}, {4, 9}};

    MST(0, graph);  // 從哪個點開始都可以，可是結果MST結構可能不同，但總權重一定一樣

    return 0;
}