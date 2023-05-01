#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;

struct Edge{
    int from, to, weight;

    Edge() = default;
    Edge(int f, int t, int w): from(f), to(t), weight(w){}
};

struct Node{
    vector<Edge> edges;
    bool visited = false;
};

class Graph{
    vector<Node> nodes;
    vector<Node> path;

    Graph(int N){
        nodes.resize(N+1);
    }

    void add_edge(int from, int to, int weight){
        nodes[from].edges.emplace_back(from, to, weight);
    }

    int DFS(int cur, int min){
        if (cur == nodes.size()-1){
            return min;
        }
        int res;
        for (auto edge : nodes[cur].edges) {
            if (!nodes[edge.to].visited and )
        }
    }
};

int main(){
    int N, M;
    cin >> N >> M;


}