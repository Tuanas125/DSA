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

class student {
public:
    string name;
    string classes;

    student(string name, string classes) {
        this->name = name;
        this->classes = classes;
    }
};

map<int, student*> m;
void insert(int id, string name, string classes) {
    m.insert({id, new student(name, classes)});
}
void infor(int id) {
    if (m.find(id) == m.end()) {
        cout << "NA, NA" << "\n";
    } else {
        cout << m[id]->name << ", " << m[id]->classes << "\n";
    }
}
void delete_(int id) {
    student* tmp = m[id];
    m.erase(id);
    delete tmp;
}
int main() {
    insert(1, "Tuan", "K61CS");
    insert(2, "Vinh", "K43CC");
    infor(3);
    infor(2);
    delete_(2);
    infor(2);
}
