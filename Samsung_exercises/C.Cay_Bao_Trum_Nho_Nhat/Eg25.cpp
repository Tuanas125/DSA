#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> iPair;

struct Graph {
    int V, E;
    vector<vector<iPair>> adjList;

    Graph(int V) : V(V) {
        adjList.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adjList[u].push_back(make_pair(v, w));
        adjList[v].push_back(make_pair(u, w));
    }

    void PrimMST() {
        priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
        vector<bool> inMST(V, false);
        vector<int> key(V, numeric_limits<int>::max());
        vector<int> parent(V, -1);

        int src = 0;

        pq.push(make_pair(0, src));
        key[src] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            inMST[u] = true;

            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push(make_pair(key[v], v));
                    parent[v] = u;
                }
            }
        }

        cout << "Cay bao trum nho nhat:\n";
        for (int i = 1; i < V; ++i) {
            cout << "Edge: " << parent[i] << " - " << i << " : " << key[i] << endl;
        }
    }
};

int main() {
    int V, E;
    cout << "Nhap so dinh va so canh cua do thi: ";
    cin >> V >> E;

    Graph graph(V);

    cout << "Nhap " << E << " canh cua do thi (dinh dau, dinh cuoi, trong so):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    graph.PrimMST();

    return 0;
}
