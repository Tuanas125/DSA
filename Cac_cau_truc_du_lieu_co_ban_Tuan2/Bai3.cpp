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
    Node* prevNode = NULL;
    Node* nextNode = NULL;
    Node(int value, Node* prevNode, Node* nextNode) {
        this->value = value;
        this->prevNode = prevNode;
        this->nextNode = nextNode;
    }
};

int count_triplets(Node* head) {
    int ans = 0;
    Node* ptr = head;
    while(ptr->nextNode != NULL) {
        ptr = ptr->nextNode;
        if(ptr->prevNode && ptr->prevNode->prevNode != NULL && ptr->value + ptr->prevNode->value + ptr->prevNode->prevNode->value == 0) {
            ans++;
        }
    }
    return ans;
}

int main(){
    freopen("square.in", "r", stdin);
    int n, ans = 0; cin >> n;
    Node* a = new Node(0, NULL, NULL);
    Node* ptr = a;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        Node* tmp = new Node(x, ptr, NULL);
        ptr->nextNode = tmp;
        ptr = ptr->nextNode;
    }
    cout << count_triplets(a);
}
