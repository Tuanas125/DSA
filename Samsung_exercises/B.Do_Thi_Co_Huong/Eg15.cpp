#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void topologicalSort(vector<vector<int>>& adj) {
    int V = adj.size();

    vector<int> indegree(V, 0);
    for (int u = 0; u < V; ++u) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }

    queue<int> sources;
    for (int i = 0; i < V; ++i) {
        if (indegree[i] == 0) {
            sources.push(i);
        }
    }

    while (!sources.empty()) {
        int u = sources.front();
        sources.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                sources.push(v);
            }
        }
    }
}

int main() {
    int V, E;
    cout << "Nhap so dinh va so canh cua do thi: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);

    cout << "Nhap " << E << " canh cua do thi (u, v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << "Thu tu topological sort: ";
    topologicalSort(adj);

    return 0;
}
