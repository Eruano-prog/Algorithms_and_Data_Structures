#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;


class Graph{
    vector<vector<int>> graph;
    vector<bool> visited;

public:

    Graph(int N){
        graph.resize(N);
        visited.resize(N, false);
        for (int i = 0; i < N; ++i) {
            graph[i].resize(N, 0);
        }
    }

    void add_edge(int from, int to, int weight){
        graph[from][to] = weight;
    }

    int DFS(int cur, vector<int>& path){
        path.push_back(cur);
        if (cur == graph.size()-1){
            return 100;
        }
        visited[cur] = true;
        int res;
        for (int i = 0; i < graph.size(); ++i) {
            if(graph[cur][i] != 0 and !visited[i]){
                res = DFS(i, path);
                if (res != 0) return std::min(graph[cur][i], res);
            }
        }
        path.pop_back();
        return 0;
    }

    int F_F(){
        int ans = 0;
        vector<int> path;
        int res = DFS(0, path);
        while(res != 0){
            ans += res;
            for (int i = path.size()-1; i >= 1; --i) {
                graph[path[i-1]][path[i]] -= res;
                graph[path[i]][path[i-1]] += res;
            }
            path.resize(0);
            for (int i = 0; i < graph.size(); ++i) {
                visited[i] = false;
            }
            res = DFS(0, path);
        }
        return ans;
    }
};

int main(){
    int N, M;
    cin >> N >> M;

    Graph graph(N);
    int f, t, w;
    for (int i = 0; i < M; ++i) {
        cin >> f >> t >> w;
        f--; t--;
        graph.add_edge(f, t, w);
    }

    cout << graph.F_F();
}