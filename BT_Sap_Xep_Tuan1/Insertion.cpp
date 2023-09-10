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

int a[102];

int main(){
    //freopen("square.in", "r", stdin);
    int n; cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 1; i < n; i++) {
        int j = i;
        while(j > 0 && a[j-1] > a[j]) {
            swap(a[j], a[j-1]);
            j = j - 1;
        }
    }

    for(int i = 0; i < n; i++) cout << a[i];
}
