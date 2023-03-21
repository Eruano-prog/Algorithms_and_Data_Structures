#include <iostream>
#include <vector>
#include <stack>

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
    int indx;

    Node(int t){
        indx = 0;
    }
};

static std::stack<Node*> ans;
static int count;

class Graph{
public:
    std::vector<Node*> nodes;

    Graph(int t){
        for (int i = 0; i < t; ++i) {
            nodes.push_back(new Node(i+1));
        }
    }

    void add_bridge(int a, int b){
        nodes[a]->bridges.push_back(nodes[b]);
    }

    void DFS(){
        for (int i = 0; i < nodes.size(); i++) {
            if(nodes[i]->color == white) {
                Visit(nodes[i]);
            }
        }
    }

    private:

    void Visit(Node* node){
        node->color = gray;
        for (Node* bridge:node->bridges){
            if (bridge->color == white){
                Visit(bridge);
            }
        }
        node->color = black;
        node->indx = count;
        count--;
    }
};


int main(){
    int n, m;
    cin >> n >> m;

    count = n;
    Graph graph(n);

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        a--; b--;
        graph.add_bridge(a, b);
    }

    graph.DFS();

    int stack[n];
    for (int i = 0; i < n; ++i) {
        cout << graph.nodes[i]->indx << ' ';
    }
}