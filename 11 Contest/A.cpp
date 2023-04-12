#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::cout;

class Graph{
    std::vector<std::vector<int>> distance;
    int N;

public:
    Graph(int n): N(n){
        distance.resize(n);
        for (int i = 0; i < n; ++i) {
            distance[i].resize(n, 2000000);
        }
        for (int i = 0; i < n; ++i) {
            distance[i][i] = 0;
        }
    }

    void add_path(int from, int to, int weight){
        distance[from][to] = weight;
    }

    void Floyd_Warshall(int K){
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    if (abs(j-i) < 1+K && abs(k-i) < 1+K) {
                        distance[j][k] = std::min(distance[i][k] + distance[j][i], distance[j][k]);
                    }
                }
            }
        }
    }

    int get_answer(int from, int to){
        if (distance[from][to] == 2000000) return -1;
        return distance[from][to];
    }
};

int main(){
    int N, M, K;
    cin >> N >> M >> K;

    Graph graph(N);

    int from, to, weight;
    for (int i = 0; i < M; ++i) {
        cin >> from >> to >> weight;
        from--; to--;
        graph.add_path(from, to, weight);
    }

    graph.Floyd_Warshall(K);

    std::queue<int> ans;
    int Q;
    cin >> Q;
    int a, b;
    for (int i = 0; i < Q; ++i) {
        cin >> a >> b;
        a--; b--;
        cout << graph.get_answer(a, b) << std::endl;
    }
}