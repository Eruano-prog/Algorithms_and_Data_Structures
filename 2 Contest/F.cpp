#include <iostream>
#include <vector>

using std::cout;
using std::cin;

enum Color{
    white,
    grey,
    black,
};

struct Node{
    std::vector<Node *> bridges;
    Color color = white;
};


class Graph{
public:
    Node* nods;
    int lenght;

    Graph(int t) {
        nods = new Node[t];
        for (int i = 0; i < t; ++i) {
            nods[i] = Node();
        }
        lenght = t;
    }

    void add_bridge(int a, int b) {
        nods[a-1].bridges.push_back(&nods[b-1]);
        nods[b-1].bridges.push_back(&nods[a-1]);
    }

    bool DFS(){
        for (int i = 0; i < lenght; ++i) {
            if(Visit(1, &nods[i])) return true;
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