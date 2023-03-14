#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::cout;
using std::cin;

struct point {
    int x, y, z;

    point(int i=0, int j=0, int k=0) : x(i), y(j), z(k) {}
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
    point end;

    Graph(point e, int E) {
        limit = E;
        end = point(e.x, e.y, e.z);
        points.resize(101, vector<vector<int>>(101));
        visited.resize(101, vector<vector<bool>>(101));

        for (int i = 0; i < 101; ++i) {
            for (int j = 0; j < 101; ++j) {
                points[i][j].resize(101, -1);
                visited[i][j].resize(101, false);
            }
        }
    }

    void start_bfs(point point) {
        order.push(point);

        points[point.x][point.y][point.z] = 0;
        visited[point.x][point.y][point.z] = true;
        BFS();
    }

    void get_answer() {
        cout << points[end.x][end.y][end.z] << std::endl;
    }

    void set_buildings(int K){
        point p{};
        int h;
        for (int i = 0; i < K; ++i) {
            cin >> p.x >> p.y >> p.z >> h;
            build(p, h);
        }
    }

private:

    void build(point p, int h){
        for (int i = 0; i < h; ++i) {
            if(p.z+i > 101) break;

            visited[p.x][p.y][p.z+i] = true;
        }
    }

    void BFS() {
        while (!order.empty()) {
            point cur = order.front();
            order.pop();

            if (cur.x == end.x && cur.y == end.y && cur.z == end.z) {
                break;
            }
            int x = cur.x, y = cur.y, z = cur.z;
            if (points[x][y][z] >= limit) {
                continue;
            }

            if (cur.x + 1 < 101 && !visited[x + 1][y][z]) {
                order.emplace(x + 1, y, z);
                points[x + 1][y][z] = points[x][y][z] + 1;
                visited[x + 1][y][z] = true;
            }
            if (cur.x - 1 >= 0 && !visited[x - 1][y][z]) {
                order.emplace(x - 1, y, z);
                points[x - 1][y][z] = points[x][y][z] + 1;
                visited[x - 1][y][z] = true;
            }
            if (cur.y + 1 < 101 && !visited[x][y + 1][z]) {
                order.emplace(x, y + 1, z);
                points[x][y + 1][z] = points[x][y][z] + 1;
                visited[x][y + 1][z] = true;
            }
            if (cur.y - 1 >= 0 && !visited[x][y - 1][z]) {
                order.emplace(x, y - 1, z);
                points[x][y - 1][z] = points[x][y][z] + 1;
                visited[x][y - 1][z] = true;
            }
            if (cur.z + 1 < 101 && !visited[x][y][z + 1]) {
                order.emplace(x, y, z + 1);
                points[x][y][z + 1] = points[x][y][z] + 1;
                visited[x][y][z + 1] = true;
            }
            if (cur.z - 1 >= 0 && !visited[x][y][z - 1]) {
                order.emplace(x, y, z - 1);
                points[x][y][z - 1] = points[x][y][z] + 1;
                visited[x][y][z - 1] = true;
            }
        }
    }
};

int main() {
    int K, E;
    cin >> K >> E;

    int x, y, z;
    cin >> x >> y >> z;
    point begin(x, y, z);

    cin >> x >> y >> z;
    point end(x, y, z);

    Graph graph(end, E);

    graph.set_buildings(K);

    graph.start_bfs(begin);

    graph.get_answer();
}