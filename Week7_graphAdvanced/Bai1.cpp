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

int n, m;
unordered_map<int, vector<int>> graph;
queue<int> q;
vector<int> topo;

int main() {
    //freopen("square.in", "r", stdin);
    freopen("jobs.txt", "r", stdin);
    freopen("jobs.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<int> indegree(n + 1, 0);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
        indegree[y]++;
    }

    for(int i = 1; i <= n; i++) if(indegree[i] == 0) q.push(i);

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for(int v : graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }

    for(int u : topo) cout << u << " ";
    cout << "\n";
}
