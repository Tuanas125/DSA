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

bool order(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

bool visitAll(vector<bool> a) {
	for(int i = 0; i<a.size(); i++){
		if(a[i] == false) return false;
	}
	return true;
}

int n, m;
vector<vector<int>> graph;
vector<vector<int>> mst;

int main()
{
    //freopen("square.in", "r", stdin);
    freopen("connection.txt", "r", stdin);
    freopen("connection.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<bool> visit(n, false);

    while(m--) {
        int u, v, w; cin >> u >> v >> w;
        graph.push_back({u, v, w});
    }

    sort(graph.begin(), graph.end(), order);

    visit[0] = true;
    int ans = 0;
    mst.push_back({graph[0][0], graph[0][1], graph[0][2]});
    visit[graph[0][0]] = true;
    visit[graph[0][1]] = true;
    ans += graph[0][2];

    while(!visitAll(visit)) {
        for(auto E : graph) {
            if(visit[E[0]] && !visit[E[1]]) {
                mst.push_back({E[0], E[1], E[2]});
                visit[E[1]] = true;
                ans += E[2];
                break;
            }
            if(!visit[E[0]] && visit[E[1]]) {
                mst.push_back({E[0], E[1], E[2]});
                visit[E[0]] = true;
                ans += E[2];
                break;
            }
        }
    }

    cout << ans << "\n";
    for(auto E : mst) cout << E[0] << " " << E[1] << " " << E[2] << "\n";
}
