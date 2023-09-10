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

vector<int> a;

vector<int> mergesort(vector<int> x) {
    if(x.size() <= 1) {
        return x;
    }

    vector<int> b, c, ans;
    int i = 0;

    for(; i <= (x.size() - 1) / 2; i++) {
        b.push_back(x[i]);
    }
    for(; i < x.size(); i++){
        c.push_back(x[i]);
    }

    b = mergesort(b);
    c = mergesort(c);

    int j = 0; i = 0;

    while(i < b.size() && j < c.size()){
        if(b[i] < c[j]) {
            ans.push_back(b[i]);
            i++;
        }
        else {
            ans.push_back(c[j]);
            j++;
        }
    }

    while(i < b.size()) {
        ans.push_back(b[i]);
        i++;
    }

    while(j < c.size()) {
        ans.push_back(c[j]);
        j++;
    }

    return ans;
}

int main(){
    freopen("square.in", "r", stdin);
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    vector<int> ans = mergesort(a);

    for(int i = 0; i < ans.size(); i++) cout << ans[i];
}
