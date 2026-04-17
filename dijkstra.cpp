#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void dijkstra_simple(int start, int goal, vector<vector<pair<int, int>>>& graph) {
    int n = graph.size();

    vector<int> distance(n, INT_MAX);
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    distance[start] = 0;

    for (int i = 0; i < n; i++) {
        int u = -1;  // u與v代表兩個節點起訖
        int min_distance = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && distance[j] < min_distance) {
                min_distance = distance[j];
                u = j;
            }
        }

        if (u == -1) {
            break;
        }

        visited[u] = true;
        if (u == goal) {
            break;
        }

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                parent[v] = u;
            }
        }
    }

    cout << "最佳化路徑: ";
    if (distance[goal] == INT_MAX) {
        cout << "無路徑" << endl;
    } else {
        vector<int> path;
        for (int node = goal; node != -1; node = parent[node]) {
            path.push_back(node);
        }

        reverse(path.begin(), path.end());

        for (int i = 0; i < path.size(); i++) {
            if (i == path.size() - 1) {
                cout << path[i];
            } else {
                cout << path[i] << " → ";
            }
        }
        cout << "\n總距離: " << distance[goal] << endl;
    }
}

int main() {
    int num_nodes = 6;

    vector<vector<pair<int, int>>> graph(num_nodes);
    graph[0] = {{1, 7}, {2, 9}, {5, 14}};  // graph[節點編號] = {{連接節點編號, 權重}, {節點編號, 權重}}
    graph[1] = {{0, 7}, {2, 10}, {3, 15}};
    graph[2] = {{0, 9}, {1, 10}, {3, 11}, {5, 2}};
    graph[3] = {{1, 15}, {2, 11}, {4, 6}};
    graph[4] = {{3, 6}, {5, 9}};
    graph[5] = {{0, 14}, {2, 2}, {4, 9}};

    dijkstra_simple(0, 4, graph);

    return 0;
}