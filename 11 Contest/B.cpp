#include <iostream>
#include <vector>

using std::cin;
using std::cout;

class Graph{
    std::vector<std::vector<int>> distance;
    int N;

public:
    Graph(int n): N(n){
        distance.resize(n);
        for (int i = 0; i < n; ++i) {
            distance[i].resize(n, 200000);
        }
        for (int i = 0; i < n; ++i) {
            distance[i][i] = 0;
        }
    }

    void add_path(int from, int to, int weight){
        distance[from][to] = weight;
        distance[to][from] = weight;
    }

    void Floyd_Warshall(){
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                for (int k = 0; k < N; ++k) {
                    distance[j][k] = std::min(distance[i][k] + distance[j][i], distance[j][k]);
                }
            }
        }
    }

    int find_max(){
        int max = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (distance[i][j] == 200000) continue;
                max = std::max(distance[i][j], max);
            }
        }
        return max;
    }
};

int main(){
    int N, M;
    cin >> N >> M;

    Graph graph(N);

    int from, to, weight;
    for (int i = 0; i < M; ++i) {
        cin >> from >> to >> weight;
        from--; to--;
        graph.add_path(from, to, weight);
    }
    graph.Floyd_Warshall();

    cout << graph.find_max();

}