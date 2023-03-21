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
        indx = t;
    }
};

static std::stack<Node*> ans;

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
        for (Node* node:nodes) {
            if(node->color == white) {
                Visit(node);
            }
        }
    }

private:

    void Visit(Node* node){
        node->color = gray;
        for (Node* bridge:node->bridges){
            if (node->color == white){
                Visit(bridge);
            }
        }
        node->color = black;
        ans.push(node);
    }
};


int main(){
    int n, m;
    cin >> n >> m;

    Graph graph(n);

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        a--; b--;
        graph.add_bridge(a, b);
    }

    graph.DFS();

    int stack[n];
    for (int i = n-1; i >= 0; --i) {
        Node* node = ans.top();
        ans.pop();
        stack[i] = node->indx;
    }
    int answ[n];
    for (int i = 0; i < n; ++i) {
        answ[stack[i]] = i+1;
    }

    for (int i = 0; i < n; ++i) {
        cout << answ[i] << ' ';
    }
}