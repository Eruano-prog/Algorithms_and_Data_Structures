#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::cin;

struct point {
    bool deleted = false, visited = false;
};

class Graph {
    vector<vector<point>> graph;
    vector<vector<std::pair<int, int>>> match;

public:
    Graph(int N, int M) {
        graph.resize(N);
        for (int i = 0; i < N; ++i) {
            graph[i].resize(M);
        }
        match.resize(N);
        for (int i = 0; i < N; ++i) {
            match[i].resize(M, std::make_pair(-1, -1));
        }
    }

    void del(int a, int b) {
        graph[a][b].deleted = true;
    }

    void clean() {
        for (auto& line : graph) {
            for (auto& point : line) {
                point.visited = false;
            }
        }
    }

    bool dfs(int cur_x, int cur_y) {
        if (graph[cur_x][cur_y].visited || graph[cur_x][cur_y].deleted) {
            return false;
        }
        graph[cur_x][cur_y].visited = true;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (i != 0 && j != 0) {
                    continue;
                }
                if (cur_x + i < 0 || cur_y + j < 0 || cur_x + i >= match.size() || cur_y + j >= match[0].size()) {
                    continue;
                }
                if (!graph[cur_x + i][cur_y + j].deleted && (match[cur_x + i][cur_y + j].first == -1 || dfs(match[cur_x + i][cur_y + j].first, match[cur_x + i][cur_y + j].second))) {
                    match[cur_x + i][cur_y + j].first = cur_x;
                    match[cur_x + i][cur_y + j].second = cur_y;
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;

    Graph G(N, M);

    int a, b;
    for (int i = 0; i < Q; ++i) {
        cin >> a >> b;
        a--;
        b--;
        G.del(a, b);
    }

    int count = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            G.clean();
            if (G.dfs(i, j)) {
                count++;
            }
        }
    }
    cout << count << std::endl;
}
