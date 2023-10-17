#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for(int i = a; i <= b; i++)
#define SQ(a) (a)*(a)

int main()
{
    //freopen("square.in", "r", stdin);
    int n, m, source, target;
    cin >> n >> m >> source >> target;
    map<int, vector<int>> graph;
    while(m--) {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<int> distance(n + 1, INT_MAX);
    distance[source] = 0;
    queue<int> q;
    q.push(source);
    while(!q.empty()) {
        int u = q.front();
        if (u == target) break;
        q.pop();
        for(int v : graph[u]) {
            q.push(v);
            distance[v] = min(distance[v], distance[u] + 1);
        }
    }
    cout << distance[target] << "\n";
}
