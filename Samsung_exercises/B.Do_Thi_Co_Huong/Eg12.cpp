#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool hasUniqueTopologicalOrder(const vector<vector<int>>& adj) {
    vector<int> in_degree(adj.size(), 0);

    for (const auto& edges : adj) {
        for (int v : edges) {
            in_degree[v]++;
        }
    }

    vector<int> topologicalOrder;
    queue<int> q;

    for (int i = 0; i < adj.size(); ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topologicalOrder.push_back(u);

        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    for (int i = 0; i < topologicalOrder.size() - 1; ++i) {
        bool connected = false;
        for (int v : adj[topologicalOrder[i]]) {
            if (v == topologicalOrder[i + 1]) {
                connected = true;
                break;
            }
        }
        if (!connected) {
            return false;
        }
    }

    return true;
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

    if (hasUniqueTopologicalOrder(adj)) {
        cout << "Do thi co thu tu to po duy nhat.\n";
    } else {
        cout << "Do thi khong co thu tu to po duy nhat.\n";
    }

    return 0;
}
