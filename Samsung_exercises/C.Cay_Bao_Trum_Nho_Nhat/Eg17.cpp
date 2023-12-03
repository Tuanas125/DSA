#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    vector<Edge> edges;

    Graph(int V, int E) : V(V), E(E) {
        edges.resize(E);
    }
};

int find(vector<int>& parent, int i) {
    if (parent[i] == -1) {
        return i;
    }
    return find(parent, parent[i]);
}

void Union(vector<int>& parent, int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

void MSTWithCycleHandling(Graph& graph) {
    vector<int> parent(graph.V, -1);
    vector<Edge> result;

    int i = 0;
    int e = 0;

    sort(graph.edges.begin(), graph.edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    while (e < graph.V - 1 && i < graph.E) {
        Edge next_edge = graph.edges[i++];

        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        if (x != y) {
            result.push_back(next_edge);
            Union(parent, x, y);
            e++;
        } else {
            cout << "Chu trinh co the xay ra, loai bo canh voi trong so lon nhat: " << next_edge.src << " - " << next_edge.dest << endl;
        }
    }
}

int main() {
    int V, E;
    cout << "Nhap so dinh va so canh cua do thi: ";
    cin >> V >> E;

    Graph graph(V, E);

    cout << "Nhap " << E << " canh cua do thi (dinh dau, dinh cuoi, trong so):\n";
    for (int i = 0; i < E; ++i) {
        cin >> graph.edges[i].src >> graph.edges[i].dest >> graph.edges[i].weight;
    }

    MSTWithCycleHandling(graph);

    return 0;
}
