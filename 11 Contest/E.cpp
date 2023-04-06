#include <iostream>

using std::cout;
using std::cin;

class Graph{
    int** weight{};
    int amount;

    Graph(int t): amount(t){
        weight[t][t];
        for (int i = 0; i < t; ++i) {
            for (int j = 0; j < t; ++j) {
                weight[i][j] = INT_MAX;
            }
        }
    }

    void Top_sort(){
        int visited[t][t]
        for
    }
};

int main(){
    int N, M, S, T;
    cin >> N >> M >> S >> T;

    for (int i = 0; i < M; ++i) {

    }
}