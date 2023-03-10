#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::cout;
using std::cin;

struct point {
    int x, y, z;

    point(int i, int j, int k) {
        x = i;
        y = j;
        z = k;
    }
};

bool operator==(point p1, point p2) {
    return p1.x == p2.x && p1.y == p2.y && p1.z == p2.z;
}

class Graph {
    queue<point> order;
    vector<vector<vector<int>>> points;
    vector<vector<vector<bool>>> visited;
    int limit;

public:
    point *end;

    Graph(point e, int E) {
        limit = E;
        end = new point(e.x, e.y, e.z);
        points.resize(100, vector<vector<int>>(100));
        visited.resize(100, vector<vector<bool>>(100));

        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 100; ++j) {
                points[i][j].resize(100, -1);
                visited[i][j].resize(100, false);
            }
        }
    }

    void start_bfs(point point) {
        order.push(point);
        points[point.x][point.y][point.z] = 0;
        BFS();
    }

    void get_answer() {
        cout << points[end->x][end->y][end->z] << std::endl;
    }

private:

    void BFS() {
        while (!order.empty()) {
            point cur = order.front();
            order.pop();
            cout << "Iteration" << std::endl;

            if (cur == *end) {
                break;
            }
            int x = cur.x, y = cur.y, z = cur.z;
            if (points[x][y][z] > limit) {
                continue;
            }

            visited[x][y][z] = true;

            if (cur.x + 1 < 100 && !visited[x + 1][y][z]) {
                order.emplace(x + 1, y, z);
                points[x + 1][y][z] = points[x][y][z] + 1;
            }
            if (cur.x - 1 >= 0 && !visited[x - 1][y][z]) {
                order.emplace(x - 1, y, z);
                points[x - 1][y][z] = points[x][y][z] + 1;
            }
            if (cur.y + 1 < 100 && !visited[x][y + 1][z]) {
                order.emplace(x, y + 1, z);
                points[x][y + 1][z] = points[x][y][z] + 1;
            }
            if (cur.y - 1 >= 0 && !visited[x][y - 1][z]) {
                order.emplace(x, y - 1, z);
                points[x][y - 1][z] = points[x][y][z] + 1;
            }
            if (cur.z + 1 < 100 && !visited[x][y][z + 1]) {
                order.emplace(x, y, z + 1);
                points[x][y][z + 1] = points[x][y][z] + 1;
            }
            if (cur.z - 1 >= 0 && !visited[x][y][z - 1]) {
                order.emplace(x, y, z - 1);
                points[x][y][z - 1] = points[x][y][z] + 1;
            }
        }
    }
};

int main() {
    int K, E;
    cin >> K >> E;

    int x, y, z;
    cin >> x >> y >> z;
    point begin(x - 1, y - 1, z - 1);

    cin >> x >> y >> z;
    point end(x - 1, y - 1, z - 1);

    Graph graph(end, E);

    graph.start_bfs(begin);

    graph.get_answer();

}