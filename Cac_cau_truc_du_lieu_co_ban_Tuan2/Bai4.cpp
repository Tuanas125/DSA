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

queue<int> q;

int main(){
    freopen("square.in", "r", stdin);
    int n; cin >> n;
    while(n--) {
        string s; cin >> s;
        if(s == "enqueue") {
            int x; cin >> x;
            q.push(x);
        }
        else {
            q.pop();
        }
    }
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}
