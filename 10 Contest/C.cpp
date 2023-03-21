#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::endl;
using std::cin;

struct Node{
    std::vector<Node*> bridges;
    bool visited = false;
};

class Graph{
public:
    std::vector<Node*> nodes;

    Graph(int t){
        nodes.reserve(t);
        for (int i = 0; i < t; ++i) {
            nodes.push_back(new Node);
        }
    }

    void add_bridge(int a, int b){
        nodes[a]->bridges.push_back(nodes[b]);
    }

    bool check(int a, int b){
        std::queue<Node*> order;
        order.push(nodes[a]);
        Node* node;
        while(!order.empty()){
            node = order.front();
            order.pop();
            if (node == nodes[b]){
                this->clear();
                return true;
            }
            for (auto nod: node->bridges) {
                if (!nod->visited) {
                    order.push(nod);
                    nod->visited = true;
                }
            }
        }
        this->clear();
        return false;
    }

    void clear(){
        for (int i = 0; i < nodes.size(); ++i) {
            nodes[i]->visited = false;
        }
    }
};

int main(){
    int N, M, Q;
    cin >> N >> M >> Q;

    Graph graph(N);

    int a, b;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        a--; b--;
        graph.add_bridge(a, b);
    }

    for (int i = 0; i < Q; ++i) {
        cin >> a >> b;
        a--; b--;
        if (graph.check(a, b) && graph.check(b, a)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

}