#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::cin;

struct Path{
    int node, weight;

    Path(int a, int w): node(a), weight(w){};
};

struct Node{
    std::vector<Path> paths;
    int dist = -1;
};

struct comp{
    bool operator()(Node* a, Node* b){
        return a->dist < b->dist;
    }
};

class Graph{
    std::vector<Node*> nodes;

public:
    Graph(int t){
        nodes.reserve(t);
        for (int i = 0; i < t; ++i) {
            nodes[i] = new Node;
        }
    }

    void add_path(int b, int e, int w){
        nodes[b]->paths.emplace_back(e, w);
    }

    void Dijkstra(int s){
        std::priority_queue<Node*, std::vector<Node*>, comp> pq;
        nodes[s]->dist = 0;
        Node* cur = nodes[s];
        bool changed;
        while(!pq.empty()){
            for (auto path:cur->paths) {
                changed = Relax(cur, path);
                if (changed){
                    pq.push(nodes[path.node]);
                }
            }
            cur = pq.top();
            pq.pop();
        }
    }

private:
    bool Relax(Node* node, Path path){
        if (nodes[path.node]->dist >= node->dist + path.weight){
            nodes[path.node]->dist = node->dist + path.weight;
            return true;
        }
        return false;
    }
};

int main(){
    int N, M, Q, S;
    cin >> N >> M >> Q >> S;

    Graph graph(N);

    int B, E, W;
    for (int i = 0; i < M; ++i) {
        cin >> B >> E >> W;
    }


}