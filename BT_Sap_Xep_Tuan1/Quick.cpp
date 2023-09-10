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

void quicksort(int arr[], int l, int h) {
    if(l < h) {
        int p = arr[h];
        int i = l - 1;
        for(int j = l; j < h; j++) {
            if(arr[j] <= p) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[h]);
        quicksort(arr, l, i);
        quicksort(arr, i + 2, h);
    }
}

int main(){
    //freopen("square.in", "r", stdin);
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    quicksort(a, 0, n-1);

    for(int i = 0; i < n; i++) cout << a[i];
}
