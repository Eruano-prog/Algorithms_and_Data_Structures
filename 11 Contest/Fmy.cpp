#include <iostream>
#include <vector>

using std::vector;
using std::pair;
using std::cout;
using std::cin;

vector<pair<long long*, long long>> history;

class DSU{
public:
    vector <long long> parent, rang;

    DSU(int n){
        parent.resize(n, -1);
        rang.resize(n, 0);
    }

    long long root(long long v){
        while (parent[v] != -1){
            v = parent[v];
        }
        return v;
    }

    void merge(long long a, long long b){
        a = this->root(a);
        b = this->root(b);

        if (a == b) return;

        if (rang[a] > rang[b]){
            history.emplace_back(&parent[b], parent[b]);
            parent[b] = a;
        }
        else if (rang[a] < rang[b]){
            history.emplace_back(&parent[a], parent[a]);
            parent[a] = b;
        }
        else{
            history.emplace_back(&parent[a], parent[a]);
            history.emplace_back(&parent[b], parent[b]);
            parent[a] = b;
            rang[b]++;
        }
    }
};

struct order{
    char com;
    long long u, v;
};
vector<order> orders;

class Segment_Tree{
    vector<pair<long long, long long>> tree;

    Segment_Tree(int n){
        tree[n*4];
    }

    void add(long long left, long long right, pair<long long, long long> edge, long long cur, long long cur_left, int cur_right){
        if (left > cur_right || right < cur_left) return;

        if (left <= cur_left && right >= cur_right) {
            tree[cur].
        }

    }
};

int main(){

}