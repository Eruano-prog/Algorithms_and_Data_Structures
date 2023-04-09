#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::string;
using std::swap;

struct Path{
    int node, weight;

    Path(int a, int w): node(a), weight(w){};
};

struct Node{
    std::vector<Path> paths;
    int dist = 10000000;
    bool visited = false;
};

class prior_queue {
public:
    std::vector <Node*> heap;

    void siftDown() {
        int i = 0;
        while (2 * i + 1 < heap.size()) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int j = left;
            if (right < heap.size() && heap[right]->dist < heap[left]->dist) {
                j = right;
            }
            if (heap[i]->dist <= heap[j]->dist) {
                break;
            }
            swap(heap[i], heap[j]);
            i = j;
        }
    }

    void siftUp(int pos) {
        while ((pos - 1) / 2 >= 0 and heap[pos]->dist < heap[(pos - 1) / 2]->dist) {
            swap(heap[pos], heap[(pos - 1) / 2]);
            pos = (pos - 1) / 2;
        }
    }


    Node* extract() {
        Node* temp = heap[0];
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        if (heap.size() > 1) { siftDown(); }
        return temp;
    }

    void push(Node* node){
        heap.push_back(node);
        siftUp(heap.size() - 1);
    }

    void decrease(Node* position) {
        for (int i = 0; i < heap.size(); i++) {
            if (heap[i] == position) {
                siftUp(i);
                return;
            }
        }
    }

    bool empty(){
        return heap.size() == 0;
    }
};

class Graph{
    std::vector<Node*> nodes;
    int count = 0;

public:
    Graph(int t){
        nodes.reserve(t);
        for (int i = 0; i < t; ++i) {
            nodes.push_back(new Node);
        }
    }

    void add_path(int b, int e, int w){
        nodes[b]->paths.emplace_back(e, w);
        nodes[e]->paths.emplace_back(b, w);
    }

    void Dijkstra(int s){
        prior_queue pq;
        nodes[s]->dist = 0;
        Node* cur;
        pq.push(nodes[s]);
        bool changed;
        while(!pq.empty()){
            cur = pq.extract();
            for (auto path:cur->paths) {
                changed = Relax(cur, path);
                if (changed){
                    pq.push(nodes[path.node]);
                }
            }
            count++;
            cur->visited = true;
        }
    }

    int get_dist(int Q){
        if (nodes[Q]->dist == 10000000){
            return -1;
        }
        return nodes[Q]->dist;
    }

private:
    bool Relax(Node* node, Path path){
        if (nodes[path.node]->dist >= node->dist + path.weight){
            nodes[path.node]->dist = node->dist + path.weight;
            return true;
        }
        return false;
    }
};

int main(){
    int N, M, Q, S;
    cin >> N >> M >> Q >> S;
    S--;
    Graph graph(N);

    int B, E, W;
    for (int i = 0; i < M; ++i) {
        cin >> B >> E >> W;
        B--; E--;
        graph.add_path(B, E, W);
    }

    graph.Dijkstra(S);

    int p;
    std::queue<int> ans;
    for (int i = 0; i < Q; ++i) {
        cin >> p;
        p--;
        ans.push(graph.get_dist(p));
    }

    while(!ans.empty()){
        cout << ans.front() << std::endl;
        ans.pop();
    }
}