#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;

int N, M;

class Graph{
    vector<vector<char>> points;
    vector<vector<bool>> visited;

    int count = 0;

public:
    Graph(){
        points.resize(N, vector<char>(M));
        visited.resize(N, vector<bool>(M, false));
        char symb;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> symb;
                points[i][j] = symb;
            }
        }
    }

    void check_points(){
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (points[i][j] == '.' && !visited[i][j]){
                    count++;
                    DFS(i, j);
                }
            }
        }
    }

    int get_amount() const{
        return count;
    }

private:

    void DFS(int i, int j){
        visited[i][j] = true;

        if ((i+1 < N) && points[i+1][j] == '.' && !visited[i+1][j]){
            DFS(i+1, j);
        }
        if ((i-1 >= 0) && points[i-1][j] == '.' && !visited[i-1][j]){
            DFS(i-1, j);
        }
        if ((j+1 < M) && points[i][j+1] == '.' && !visited[i][j+1]){
            DFS(i, j+1);
        }
        if ((j-1 >= 0) && points[i][j-1] == '.' && !visited[i][j-1]){
            DFS(i, j-1);
        }
    }
};

int main(){
    cin >> N >> M;

    Graph graph;

    graph.check_points();

    cout << graph.get_amount();

    return 0;
}