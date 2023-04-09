#include <iostream>
#include <vector>
#include <stack>

using std::cout;
using std::cin;

struct Path{
    int weight, node;

    Path(int b, int w): node(b), weight(w){}
};
struct Node{
    std::vector<Path> paths;
    bool visited = false;
};

class Graph{
    std::vector<Node> nodes;
    std::stack<int> temp;
    std::vector<int> dist;
    int size, start, end;

public:
    Graph(int t, int S, int E): size(t), start(S-1), end(E-1){
        nodes.resize(t);
        dist.resize(t, 9999999);
    }

    void add_bridge(int a, int b, int w){
        nodes[a].paths.emplace_back(b, w);
    }

    void Top_sort(){
        for (int i = 0; i < size; ++i) {
            if (!nodes[i].visited){
                DFS(i);
            }
        }
        this->Clean();
    }

    void DAG(){
        while(temp.top() != start){
            temp.pop();
        }
        int cur = temp.top();
        dist[start] = 0;
        while(!temp.empty()){
            if (dist[cur] != 9999999) {
                for (auto path: nodes[cur].paths) {
                    dist[path.node] = std::min(dist[path.node], dist[cur] + path.weight);
                }
            }
            cur = temp.top();
            temp.pop();
        }
        if (dist[end] == 9999999){
            cout << -1;
            return;
        }
        cout << dist[end];
    }
private:
    void Clean(){
        for (int i = 0; i < size; ++i) {
            nodes[i].visited = false;
        }
    }
    void DFS(int i){
        nodes[i].visited = true;
        for (auto path:nodes[i].paths) {
            if (!nodes[path.node].visited){
                DFS(path.node);
            }
        }
        temp.push(i);
    }

};

int main(){
    int N, M, S, T;
    cin >> N >> M >> S >> T;

    Graph graph(N, S, T);
    int a, b, w;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b >> w;
        a--; b--;
        graph.add_bridge(a, b, w);
    }

    graph.Top_sort();

    graph.DAG();
}