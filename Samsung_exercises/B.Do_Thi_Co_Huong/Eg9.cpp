#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Graph {
private:
    unordered_map<int, vector<int>> adj;
    int V;

public:
    Graph(int vertices) : V(vertices) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    bool isEulerianCycle() {
        vector<bool> visited(V, false);
        DFSUtil(0, visited);

        for (int i = 0; i < V; ++i) {
            if (!visited[i] && !adj[i].empty()) {
                return false;
            }
        }
        vector<int> in_degree(V, 0), out_degree(V, 0);

        for (int i = 0; i < V; ++i) {
            out_degree[i] = adj[i].size();
            for (int v : adj[i]) {
                in_degree[v]++;
            }
        }

        for (int i = 0; i < V; ++i) {
            if (in_degree[i] != out_degree[i]) {
                return false;
            }
        }

        return true;
    }

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        for (int i : adj[v]) {
            if (!visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }

    void printEulerianCycle() {
        if (!isEulerianCycle()) {
            cout << "Khong co chu trinh Euler.\n";
            return;
        }

        vector<int> path;
        stack<int> st;
        int current_vertex = 0;
        st.push(current_vertex);

        while (!st.empty()) {
            if (!adj[current_vertex].empty()) {
                st.push(current_vertex);
                int next_vertex = adj[current_vertex].back();
                adj[current_vertex].pop_back();
                current_vertex = next_vertex;
            } else {
                path.push_back(current_vertex);
                current_vertex = st.top();
                st.pop();
            }
        }

        cout << "Chu trinh Euler: ";
        for (auto it = path.rbegin(); it != path.rend(); ++it) {
            cout << *it;
            if (it != path.rend() - 1) {
                cout << " - ";
            }
        }
        cout << "\n";
    }
};

int main() {
    int V, E;
    cout << "Nhap so dinh va so canh cua do thi: ";
    cin >> V >> E;

    Graph g(V);

    cout << "Nhap " << E << " canh cua do thi (u, v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.printEulerianCycle();

    return 0;
}
