#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Graph {
private:
    int V; // Số đỉnh
    vector<vector<int>> adj; // Danh sách kề

public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int v, vector<bool>& visited) {
        visited[v] = true;

        for (int u : adj[v]) {
            if (!visited[u]) {
                DFS(u, visited);
            }
        }
    }

    bool isEdgeConnected() {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < adj[i].size(); ++j) {
                int u = i;
                int v = adj[i][j];

                adj[u].erase(adj[u].begin() + j);
                adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
                vector<bool> visited(V, false);
                int components = 0;

                for (int k = 0; k < V; ++k) {
                    if (!visited[k]) {
                        DFS(k, visited);
                        components++;
                    }
                }
                adj[u].insert(adj[u].begin() + j, v);
                adj[v].insert(find(adj[v].begin(), adj[v].end(), u), u);
                if (components > 1) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    int V, E;
    cout << "Nhap so dinh va canh do thi: ";
    cin >> V >> E;

    Graph g(V);

    cout << "Nhap " << E << " canh cua do thi (u, v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    bool edgeConnected = g.isEdgeConnected();
    if (edgeConnected) {
        cout << "Do thi co tinh lien thong canh\n";
    } else {
        cout << "Do thi khong co tinh lien thong canh\n";
    }

    return 0;
}
