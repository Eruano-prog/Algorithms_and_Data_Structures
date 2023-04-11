#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::cin;

struct Path{
    int from, to, weight;

    Path(int f, int t, int w):from(f), to(t), weight(w){}
};

class Graph{
    std::vector<Path> paths;
    std::vector<int> distance, parents;
    int size;

public:
    Graph(int n, int m): size(n){
        paths.reserve(m);
        distance.resize(n, 100000);
        parents.resize(n, 100000);
    }

    void add_path(int from, int to, int weight){
        paths.emplace_back(from, to, weight);
    }

    int Bellman_Ford(){
        int f;
        for (int i = 0; i < size-1; ++i) {
            f = false;
            for (auto path : paths) {
                f = f || Relax(path);
            }
            if (!f) return -1;
        }
        for (auto path : paths) {
            if(Relax(path)) return path.to;
        }
        return -1;
    }

    int recover_cycle(int node){
        std::vector<int> ans;
        bool visited[size];
        for (int i = 0; i < size; ++i) {
            visited[i] = false;
        }
        int cur = parents[node];
        if (cur == 100000) return -1;
        while(!visited[cur]){
            visited[cur] = true;
            cur = parents[cur];
            if (cur == 100000) return -1;
        }
        int point = cur;
        do{
            ans.push_back(cur);
            cur = parents[cur];
        } while (point != cur);
        return ans.size();
    }

private:
    bool Relax(Path path){
        if (distance[path.from] + path.weight < distance[path.to]){
            distance[path.to] = distance[path.from]+path.weight;
            parents[path.to] = path.from;
            return true;
        }
        return false;
    }
};

int main(){
    int N, k;
    cin >> N >> k;
    int n, m;
    int from, to, weight;
    int node;
    int size;
    std::queue<int> ans;
    for (int i = 0; i < N; ++i) {
        cin >> n >> m;
        Graph graph(n, m);
        for (int j = 0; j < m; ++j) {
            cin >> from >> to >> weight;
            from--; to--;
            graph.add_path(from, to, weight);
        }

        node = graph.Bellman_Ford();
        if (node == -1){
            cout << "YES" << std::endl;
        }
        else{
            size = graph.recover_cycle(node);
            if (size < k || size == -1){
                cout << "YES" << std::endl;
            }
            else{
                cout << "NO" << std::endl;
            }
        }
    }
}