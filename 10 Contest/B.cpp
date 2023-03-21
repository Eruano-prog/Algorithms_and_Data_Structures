#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::cin;

struct Node{
    std::vector<Node*> bridges;
    bool visited = false;
};

class Graph{
public:
    std::vector<Node*> nodes;

    Graph(int t){
        for (int i = 0; i < t; ++i) {
            nodes.push_back(new Node);
        }
    }

    void add_bridge(int a, int b){
        nodes[a]->bridges.push_back(nodes[b]);
        nodes[b]->bridges.push_back(nodes[a]);
    }

    void delete_bridge(int a, int b){
        for (int i = 0; i < nodes[a]->bridges.size(); ++i) {
            if (nodes[a]->bridges[i] == nodes[b]){
                nodes[a]->bridges[i] = nullptr;
            }
        }

        for (int i = 0; i < nodes[b]->bridges.size(); ++i) {
            if (nodes[b]->bridges[i] == nodes[a]){
                nodes[b]->bridges[i] = nullptr;
            }
        }
    }

    bool check(int a, int b){
        std::queue<Node*> order;
        order.push(nodes[a]);
        nodes[a]->visited = true;
        Node* node;
        while(!order.empty()){
            node = order.front();
            order.pop();
            if (node == nullptr){
                continue;
            }
            if (node == nodes[b]){
                return true;
            }
            for (auto nod: node->bridges) {
                if(nod == NULL || nod->visited) continue;
                else{
                    order.push(nod);
                    nod->visited = true;
                }
            }
        }
        return false;
    }

    void clear(){
        for (auto node:nodes) {
            node->visited = false;
        }
    }
};

int main(){
    int n, m, q;
    cin >> n >> m >> q;

    Graph gr(n);

    int a, b;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        a--; b--;
        gr.add_bridge(a, b);
    }

    char com;
    for (int i = 0; i < q; ++i) {
        cin >> com >> a >> b;
        a--; b--;
        if (com == '-'){
            gr.delete_bridge(a, b);
        }
        if (com == '?'){
            if(gr.check(a, b)){
                cout << "YES" << std::endl;
            }
            else{
                cout << "NO" << std::endl;
            }
            gr.clear();
        }
    }
}