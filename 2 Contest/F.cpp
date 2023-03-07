#include <iostream>
#include <vector>

using std::cout;
using std::cin;

enum Color{
    white,
    grey,
    black,
};

struct Node {
    std::vector<Node *> bridges;
    Color color = white;
};


class Graph {
public:
    std::vector<Node *> nodes;
    int lenght;

    Graph(int t) {
        for (int i = 0; i < t; ++i) {
            nodes.push_back(new Node);
            lenght = t;
        }
    }

    void add_bridge(int a, int b) {
        nodes[a - 1]->bridges.push_back(nodes[b - 1]);
        nodes[b - 1]->bridges.push_back(nodes[a - 1]);
    }

    bool DFS(){
        for (Node* node:nodes) {
            if(Visit(1, node)) return true;
        }
        return false;
    }
private:
    bool Visit(int len, Node* node){
        if (len == lenght){
            return true;
        }
        node->color = grey;
        for (auto bridge:node->bridges) {
            if (bridge->color != white){
                continue;
            }
            if (Visit(len+1, bridge)){
                return true;
            }
        }
        node->color = white;
        return false;
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    Graph graph(N);

    int a, b;

    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        graph.add_bridge(a, b);
    }
    if (graph.DFS()){
        cout << "YES" << std::endl;
    }
    else{
        cout << "NO" << std::endl;
    }

    return 0;
}