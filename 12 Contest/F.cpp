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

void insertion_sort(vector<Edge>& array){
    for(int i=1; i < array.size(); i++){
        Edge key = array[i];
        int j = i-1;
        while(j > -1 & array[j].weight > key.weight){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

int main(){
    int N, M;
    cin >> N >> M;


    vector<Edge> edges;
    edges.reserve(M);
    int f, t, w;
    for (int i = 0; i < M; ++i) {
        cin >> f >> t >> w;
        edges.emplace_back(f, t, w);
    }
    insertion_sort(edges);


    long long second = 1000000;
    int first = 0;
    for (int j = -1; j < M; ++j) {
        int count = 0;
        long long ans = 0;
        DSU dsu(N);
        for (int i = 0; i < M; ++i) {
            if (i == j) continue;
            auto edge = edges[i];
            if(count < N-1 and !dsu.check(edge.from, edge.to)){
                ans += edge.weight;
                dsu.merge(edge.from, edge.to);
                count++;
            }
        }
        if(first == 0){
            cout << ans << ' ';
            first = ans;
        }
        else {
            if (ans != first)
                second = std::min(second, ans);
        }
    }
    cout << second;
}