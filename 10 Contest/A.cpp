#include <iostream>
#include <vector>

using std::endl;
using std::cout;
using std::cin;

struct Node{
    std::vector<Node*> bridges;
    int component = -1;
};

class Graph{
public:
    std::vector<Node*> nodes;
    std::vector<int> danger;
    int components = 1;

    Graph(int t){
        nodes.reserve(t);
        for (int i = 0; i < t; ++i) {
            nodes.push_back(new Node);
        }
    }

    void add_bridge(int a, int b){
        nodes[a]->bridges.push_back(nodes[b]);
        nodes[b]->bridges.push_back(nodes[a]);
    }

    void DFS(){
        for (int i = 0; i < nodes.size(); i++) {
            if(nodes[i]->component == -1) {
                Visit(nodes[i], components);
                components++;
            }
        }
        danger.resize(components, 0);
    }

    void add_danger(int x){
        int comp = nodes[x]->component;
        danger[comp] = 1;
    }

    void print_verts(){
        for(auto node:nodes){
            cout << node->component << ' ';
        }
        cout << endl;
    }

private:

    void Visit(Node* node, int comp){
        node->component = comp;
        for (Node* bridge:node->bridges){
            if (bridge->component == -1){
                Visit(bridge, comp);
            }
        }
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

    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if(x == 1){
            graph.add_danger(i);
        }
    }

    cout << graph.components-1 << endl;

    graph.print_verts();

    for (int i = 1; i < graph.components; ++i) {
        cout << graph.danger[i] << ' ';
    }
}