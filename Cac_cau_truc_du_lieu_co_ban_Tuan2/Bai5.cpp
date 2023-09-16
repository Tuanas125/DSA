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

stack<int> st;

int main(){
    freopen("square.in", "r", stdin);
    int n; cin >> n;
    while(n--) {
        string s; cin >> s;
        if(s == "push") {
            int x; cin >> x;
            st.push(x);
        }
        else {
            st.pop();
        }
    }
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}
