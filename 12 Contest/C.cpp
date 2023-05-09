#include <iostream>
#include <vector>
#include <stack>

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
    int from, to;
    unsigned long long weight, answer = -1;

    Edge() = default;
    void fill(int f, int t, long long w){
        from = f;
        to = t;
        weight = w;
    }
};



void swap(Edge* pF, Edge* pS){
    Edge key = *pF;
    *pF = *pS;
    *pS = key;
}



int QuickSort(vector<Edge>& edges, int left, int right){
    int l = left, r = right;
    Edge p = edges[(left + right) / 2];

    while(l <= r){
        while (edges[l].weight < p.weight){
            l++;
        }
        while (edges[r].weight > p.weight){
            r--;
        }
        if(l >= r){
            break;
        }
        swap(&edges[l++], &edges[r--]);
    }
    return r;
}

void quick(vector<Edge>& edges, int left, int right){
    if (left < right){
        int q = QuickSort(edges, left, right);
        quick(edges, left, q);
        quick(edges, q+1, right);
    }
}


int main(){
    int N, M;
    cin >> N >> M;

    vector<Edge> edges;
    edges.resize(M);
    int f, t, w;
    for (int i = 0; i < M; ++i) {
        cin >> f >> t >> w;
        edges[i].fill(f, t, w);
    }

    vector<Edge> sorted = edges;

    quick(sorted, 0, M-1);
    std::stack<Edge*> used;
    DSU dsu(N);
    int count = 0;
    unsigned long long ans = 0;
    for (int i = 0; i < M; ++i) {
        auto edge = sorted[i];
        if (count < N - 1 and !dsu.check(edge.from, edge.to)) {
            ans += edge.weight;
            dsu.merge(edge.from, edge.to);
            used.push(&edge);
            count++;
        }
    }
    while(!used.empty()){
        used.top()->answer = ans;
        used.pop();
    }
    cout << ans << std::endl;
}