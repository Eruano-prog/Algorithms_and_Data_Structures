#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;

struct point{
    bool top, right, bottom, left, deleted = false;

    point(bool t): top(t), right(t), bottom(t), left(t){}

    void fill(bool t){
        top = t;
        right = t;
        bottom = t;
        left = t;
    };
};

class Graph{
    vector<vector<point>> graph;

public:
    Graph(int N, int M){
        graph.resize(N);
        for (int i = 0; i < N; ++i) {
            graph[i].resize(M, false);
        }
        bool var = false;
        for (int i = 0; i < M; ++i) {
            for (int j = var; j < N; j+=2) {
                graph[i][j].fill(true);
            }
            var = !var;
        }
    }

    void del(int a, int b) {
        graph[a][b].deleted = true;
    }


};

int main(){
    int N, M, Q;
    cin >> N >> M >> Q;

    Graph G(N, M);


    int a, b;
    for (int i = 0; i < Q; ++i) {
        cin >> a >> b;
        a--; b--;
        G.del(a, b);
    }
}