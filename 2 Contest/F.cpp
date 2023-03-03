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

    void DFS(){
        for (Node* node:nodes) {
            if(node->color== white) {
                Visit(node);
            }
        }
    }
private:

    void Visit(Node* node){
        node->color = gray;
        int count = 0;
        for (Node* bridge:node->bridges){
            if(bridge->color == gray){
                count++;
            }
            if(bridge->color == white){
                Visit(bridge);
            }
        }
        if (count > 1){
            flag = 1;
        }
        node->color = black;
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    Graph graph(N);

    return 0;
}