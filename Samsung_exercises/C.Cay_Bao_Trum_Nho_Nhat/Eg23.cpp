#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent, rank;
};

struct Graph {
    int V, E;
    vector<Edge> edges;

    Graph(int V, int E) : V(V), E(E) {
        edges.resize(E);
    }
};

int find(vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void Union(vector<Subset>& subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank) {
        subsets[xroot].parent = yroot;
    } else if (subsets[xroot].rank > subsets[yroot].rank) {
        subsets[yroot].parent = xroot;
    } else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void BoruvkaMST(Graph& graph) {
    int V = graph.V;
    vector<Edge> result(V - 1);
    vector<Subset> subsets(V);

    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int numTrees = V;
    int index = 0;

    while (numTrees > 1) {
        vector<Edge> cheapest(V);

        for (int i = 0; i < V; ++i) {
            cheapest[i].weight = INT_MAX;
        }

        for (int i = 0; i < graph.E; ++i) {
            int set1 = find(subsets, graph.edges[i].src);
            int set2 = find(subsets, graph.edges[i].dest);

            if (set1 != set2) {
                if (graph.edges[i].weight < cheapest[set1].weight) {
                    cheapest[set1] = graph.edges[i];
                }
                if (graph.edges[i].weight < cheapest[set2].weight) {
                    cheapest[set2] = graph.edges[i];
                }
            }
        }

        for (int i = 0; i < V; ++i) {
            if (cheapest[i].weight != INT_MAX) {
                int set1 = find(subsets, cheapest[i].src);
                int set2 = find(subsets, cheapest[i].dest);

                if (set1 != set2) {
                    result[index++] = cheapest[i];
                    Union(subsets, set1, set2);
                    numTrees--;
                }
            }
        }
    }

    for (int i = 0; i < V - 1; ++i) {
        cout << result[i].src << " - " << result[i].dest << " : " << result[i].weight << endl;
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

    BoruvkaMST(graph);

    return 0;
}
