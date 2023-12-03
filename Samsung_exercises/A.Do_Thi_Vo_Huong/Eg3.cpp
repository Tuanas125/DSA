#include <iostream>
#include <vector>

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

    int countParallelEdges() {
        int parallelEdges = 0;

        for (int u = 0; u < V; ++u) {
            for (int i = 0; i < adj[u].size(); ++i) {
                int v = adj[u][i];
                for (int j = i + 1; j < adj[u].size(); ++j) {
                    if (adj[u][j] == v) {
                        parallelEdges++;
                    }
                }
            }
        }
        return parallelEdges / 2;
    }
};

int main() {
    int V, E;
    cout << "Nhap dinh va canh do thi: ";
    cin >> V >> E;

    Graph g(V);

    cout << "Nhap " << E << " canh cua do thi (u, v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int parallelEdges = g.countParallelEdges();
    cout << "So canh song song trong do thi: " << parallelEdges << endl;

    return 0;
}
