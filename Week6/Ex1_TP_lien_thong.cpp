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
    int n, m; cin >> n >> m;
    map<int, vector<int>> graph;
    while(m--) {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<bool> visited(n + 1, false);
    int components = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            components++;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(int v : graph[u]) {
                    if (!visited[v]) {
                        q.push(v);
                        visited[v] = true;
                    }
                }
            }
        }
    }
    cout << components << "\n";
}
