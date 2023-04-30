#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::cout;
using std::cin;

class DSU{
public:
    vector<int> parents;
    vector<int> rang;

    DSU(int N){
        N++;
        parents.resize(N, -1);
        rang.resize(N, 0);
    }

    void merge(int a, int b){
        int root_a = root(a);
        int root_b = root(b);

        if (rang[root_a] > rang[root_b]){
            parents[root_b] = root_a;
        }
        else if(rang[root_a] < rang[root_b]){
            parents[root_a] = root_b;
        }
        else{
            parents[root_a] = root_b;
            rang[root_b]++;
        }
    }

    bool check(int a, int b){
        return root(a) == root(b);
    }

    int root(int a){
        int cur = a;
        while(parents[cur] != -1){
            cur = parents[cur];
        }
        int it = 0;
        while(parents[a] != -1){
            it = parents[a];
            parents[a] = cur;
            a = it;
        }
        return cur;
    }
};

struct Edge {
    int from, to, weight;

    Edge(int from, int to, int weight): from(from), to(to), weight(weight){}
};

struct Compare{
    bool operator()(const Edge& p1, const Edge& p2) {
        return p1.weight > p2.weight;
    }
};

int main(){
    int N, M;
    cin >> N >> M;

    DSU dsu(N);

    std::priority_queue<Edge, vector<Edge>, Compare> pq;

    int f, t, w;
    for (int i = 0; i < M; ++i) {
        cin >> f >> t >> w;
        pq.emplace(f, t, w);
    }

    int count = 0;
    long long ans = 0;
    while(!pq.empty()){
        auto edge = pq.top();
        pq.pop();
        if(count < N-1 and !dsu.check(edge.from, edge.to)){
            ans += edge.weight;
            dsu.merge(edge.from, edge.to);
            count++;
        }
    }
    cout << ans;
}