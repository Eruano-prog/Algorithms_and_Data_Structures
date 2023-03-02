#include <iostream>
#include <vector>

using std::cout;
using std::cin;

enum Color{
    white,
    gray,
    black,
};

struct Node{
    std::vector<int> bridges;
    Color color = white;

    Node(int t){
        for (int i = 0; i < t; ++i) {
            bridges.push_back(0);
        }
    }
};


class Graph{
public:
    std::vector<Node*> nodes;

     Graph(int t){
         for (int i = 0; i < t; ++i) {
             nodes.push_back(new Node(t));
         }
     }

    void add_bridge(int a, int b){
        nodes[a-1]->bridges[b-1]++;
        nodes[b-1]->bridges[a-1]++;
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
        for (int bridge:node->bridges){
            if(nodes[bridge]->color == white){
                Visit(nodes[bridge]);
            }
            if(nodes[bridge]->color == gray){
                count++;
            }
        }
        if (count > 1){
            cout << "YES";
        }
        node->color = black;
     }
};

int main(){
    int N, M;
    cin >> N >> M;

    Graph graph(N);

    int a, b;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        graph.add_bridge(a, b);
    }
    graph.DFS();


    return 0;
}