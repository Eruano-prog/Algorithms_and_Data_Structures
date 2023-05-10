#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 5;

struct Edge {
    int u, v, w, id;
    Edge(int u, int v, int w, int id) : u(u), v(v), w(w), id(id) {}
};

vector<Edge> edges;
int parent[MAXN], rank[MAXN];
long long mst_weight[MAXN], dist[MAXN];
bool used[MAXN];

int find(int x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unite(int x, int y, int w) {
    x = find(x);
    y = find(y);
    if (x == y) {
        return;
    }
    if (rank[x] < rank[y]) {
        swap(x, y);
    }
    parent[y] = x;
    mst_weight[x] += mst_weight[y] + w;
    if (rank[x] == rank[y]) {
        rank[x]++;
    }
}

void kruskal(int n) {
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.w < b.w;
    });
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        mst_weight[i] = 0;
    }
    for (const auto& edge : edges) {
        int u = edge.u, v = edge.v, w = edge.w, id = edge.id;
        if (find(u) != find(v)) {
            used[id] = true;
            unite(u, v, w);
        }
    }
}

void dfs(int u, int p, long long w, vector<vector<pair<int, int>>>& adj) {
    dist[u] = w;
    for (const auto& edge : adj[u]) {
        int v = edge.first, d = edge.second;
        if (v != p) {
            dfs(v, u, w + d, adj);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w, i);
    }

    kruskal(n);

    for (const auto& edge : edges) {
        if (!used[edge.id]) {
            int v = edge.v, u = edge.u, w = edge.w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
    }

    dfs(1, 0, 0, adj);

    long long ans = 0;
    for (int i = 2; i <= n; i++) {
        ans += dist[i];
    }
    cout << ans << '\n';

    return 0;
}
