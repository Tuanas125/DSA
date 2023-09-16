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

struct Node {
    int value;
    Node* nextNode = NULL;
    Node(int value, Node* nextNode) {
        this->value = value;
        this->nextNode = nextNode;
    }
};

int main(){
    freopen("square.in", "r", stdin);
    Node* a = new Node(0, NULL);
    int n; cin >> n;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if(s == "insert") {
            int p, x; cin >> p >> x;
            Node* ptr = a;
            while(p--) {
                ptr = ptr->nextNode;
            }
            Node* tmp = new Node(x, ptr->nextNode);
            ptr->nextNode = tmp;
        }
        else {
            int p; cin >> p;
            Node* ptr = a;
            while(p--) {
                ptr = ptr->nextNode;
            }
            ptr->nextNode = ptr->nextNode->nextNode;
        }
    }

    Node* ptr = a;
    while(ptr->nextNode != NULL) {
        cout << ptr->nextNode->value << " ";
        ptr = ptr->nextNode;
    }
}
