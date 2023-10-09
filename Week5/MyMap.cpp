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
    int id;
    string name;
    string classes;
    student(int id, string name, string classes) {
        this->id = id;
        this->name = name;
        this->classes = classes;
    }
    void print () {
        cout << name << ", " << classes << "\n";
    }
};

class mymap {
private:
    student *arr[10000];
public:
    mymap() {
        for (int i = 0; i < 10000; i++) {
            arr[i] = NULL;
        }
    }
    void insert(int id, string name, string classes) {
        student *s = new student(id, name, classes);
        int index = s->id % 10000;
        arr[index] = s;
    }
    void infor(int id) {
        int index = id % 10000;
        if (arr[id] == NULL) {
            cout << "NA, NA" << "\n";
        }
        else {
            arr[id]->print();
        }
    }
    void delete_(int id) {
        int index = id % INT_MAX;
        arr[index] = NULL;
    }
};

int main() {
    mymap m;
    m.insert(1, "Tuan", "K61CS");
    m.insert(2, "Vinh", "K43CC");
    m.infor(3);
    m.infor(2);
    m.delete_(2);
    m.infor(2);
}
