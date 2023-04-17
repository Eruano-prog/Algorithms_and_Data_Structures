#include <iostream>
#include <vector>
#include <set>

using std::vector;
using std::pair;
using std::cout;
using std::cin;

vector<pair<long long*, long long>> history;

class DSU{
public:
    vector <long long> parent, rang;

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
public:
    vector<vector<pair<long long, long long>>> tree;
    DSU dsu;

    Segment_Tree(int N){
        dsu.parent.resize(N, -1);
        dsu.rang.resize(N, 0);
        orders.resize(N);
        tree.resize(N*4);
    }

    void add(long long left, long long right, pair<long long, long long> edge, long long cur, long long cur_left, int cur_right){
        if (left > cur_right || right < cur_left) return;

        if (left <= cur_left && right >= cur_right) {
            tree[cur].push_back(edge);
            return;
        }

        long long mid = (cur_right+cur_left) / 2;
        add(left, right, edge, cur*2+1, cur_left, mid);
        add(left, right, edge, cur*2+2, mid+1, cur_right);
    }

    void traversal(long long cur, long long cur_left, long long cur_right){
        long long start = history.size();

        for (auto edge : tree[cur]) {
            dsu.merge(edge.first, edge.second);
        }

        if (cur_left == cur_right){
            if (orders[cur_right].com == '?'){
                if(dsu.root(orders[cur_right].v) == dsu.root(orders[cur_right].u)){
                    cout << "YES" << std::endl;
                }
                else{
                    cout << "NO" << std::endl;
                }
            }
        }
        else{
            long long mid = (cur_left + cur_right) / 2;
            traversal(cur * 2 + 1, cur_left, mid);
            traversal(cur * 2 + 2, mid+1, cur_right);
        }

        while ((long long)history.size() > start){
            *history.back().first = history.back().second;
            history.pop_back();
        }
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m >> q;
    Segment_Tree tree((m+q) * 4);

    std::set < pair <pair<long long, long long>, long long> > edges;
    for (int i = 0; i < m; ++i) {
        cin >> orders[i].u >> orders[i].v;
        if (orders[i].u > orders[i].v) std::swap(orders[i].u, orders[i].v);
        orders[i].com = '+';
        edges.emplace(pair<long long, long long>(orders[i].u, orders[i].v), i);
    }

    for (int i = m; i < q+m; ++i) {
        cin >> orders[i].com >> orders[i].u >> orders[i].v;
        if (orders[i].u > orders[i].v) std::swap(orders[i].u, orders[i].v);

        if (orders[i].com == '-'){
            auto iter = edges.lower_bound(make_pair(pair<long long, long long>(orders[i].u, orders[i].v), 0));
            tree.add(iter->second, i, iter->first, 0, 0, m + q - 1);
            edges.erase(iter);
        }
    }

    for (auto edge : edges) {
        tree.add(edge.second, m + q - 1, edge.first, 0, 0, m + q - 1);
    }

    tree.traversal(0, 0, m + q - 1);

    return 0;
}