#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;

enum Color{
    white,
    gray,
    black,
};

struct Node{
    std::vector<Node*> bridges;
    Color color = white;

};


class Graph{
public:
    std::vector<Node*> nodes;


    void add_node(){
        nodes.push_back(new Node());
    }

    void add_bridge(int a, int b){
        nodes.back()->bridges;
    }

    void DFS(){
        for (Node* node:nodes) {
            if(node->color== white) {
                Visit(node);
            }
        }
    }

private:
    int count = 0;

    void Visit(Node* node){
        node->color = gray;
        for (Node* bridge:node->bridges){
            if(bridge->color == white){
                Visit(bridge);
            }
        }
        node->color = black;
    }
};

int main(){
    int n, m;
    std::cin >> n >> m;

    char M[n][m];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> M[i][j];
        }
    }


    Graph graph;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (M[i][j] == '.'){
                graph.add_node();
                
            }
        }
    }

    return 0;
}