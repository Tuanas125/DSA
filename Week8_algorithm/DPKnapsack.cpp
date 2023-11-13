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

int w[102], v[102];
ll f[102][100005];

int main(){
    //freopen("square.in", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, W;
    cin >> n >> W;

    for(int i=1; i<=n; i++){
        cin >> w[i] >> v[i];
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            if(w[i]>j) f[i][j] = f[i-1][j];
            else f[i][j] = max(f[i-1][j], v[i]+f[i-1][j-w[i]]);
        }
    }

    cout << f[n][W];
}
