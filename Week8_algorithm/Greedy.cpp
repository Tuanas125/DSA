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

struct thing{
    int value, weight;
    double valuePerWeight;
} a[1003];

bool cmp(thing x, thing y) {
    return x.valuePerWeight > y.valuePerWeight;
}

int main() {
    //freopen("square.in", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, W, ans = 0;
    cin >> n >> W;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].value >> a[i].weight;
        a[i].valuePerWeight = a[i].value / a[i].weight;
    }

    sort(a+1,a+n+1, cmp);

    for (int i = 1; i <= n; i++){
        if (W >= a[i].weight){
            ans += a[i].value;
            W -= a[i].weight;
        }
    }
    cout << ans;
}
