#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::cin;

enum Color{
    white,
    black,
};

struct Node {
    std::vector<Node *> bridges;
    Color color = white;
    int distance = -1;
};


class Graph {
public:
    std::vector<Node *> nodes;
    std::queue<Node *> order;

    Graph(int t) {
        for (int i = 0; i < t; ++i) {
            nodes.push_back(new Node);
        }
    }

    void add_bridge(int a, int b) {
        nodes[a - 1]->bridges.push_back(nodes[b - 1]);
        nodes[b - 1]->bridges.push_back(nodes[a - 1]);
    }

    void BFS(){
        while(not order.empty()){
            Node* node = order.front();
            order.pop();
            node->color = black;
            for (Node* bridge : node->bridges) {
                if(bridge->color != black){
                    if(bridge->distance == -1){
                        bridge->distance = node->distance + 1;
                    }
                    order.push(bridge);
                }
            }
        }
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
    int S, F;
    cin >> S >> F;
    graph.order.push(graph.nodes[S-1]);
    graph.nodes[S-1]->distance = 0;
    graph.BFS();

    cout << graph.nodes[F-1]->distance;

    return 0;
}