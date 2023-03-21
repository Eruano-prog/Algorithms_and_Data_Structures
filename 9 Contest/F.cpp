#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::cin;

enum Color{
    white,
    grey,
    black,
};

struct Node {
    std::vector<Node *> bridges;
    Color color = white;
    int distance = -1, count = 0;
};


class Graph{
public:
    std::vector<Node> nods;
    int lenght;
    std::queue<Node *> order;

    Graph(int t) {
        nods.resize(t, Node());
        lenght = t;
    }

    void add_bridge(int a, int b) {
        nods[a-1].bridges.push_back(&nods[b-1]);
        nods[a-1].count++;

        nods[b-1].bridges.push_back(&nods[a-1]);
        nods[b-1].count++;
    }

    bool DFS(int n){
        if(Visit(1, &nods[n])) return true;
        return false;
    }

    int find_single(){
        int amount = 0;
        int indx = -1;
        for (int i = 0; i < lenght; ++i) {
            if (nods[i].count == 1){
                amount++;
                indx = i;
            }
        }
        if (amount > 2 || amount == 0){
            return -1;
        }
        else{
            return indx;
        }
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

    int indx = graph.find_single();

    if (indx != -1 && graph.DFS(indx)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}