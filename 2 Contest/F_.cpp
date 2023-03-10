#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> perm;

bool has_hamiltonian_path() {
    do {
        bool found_path = true;
        for (int i = 1; i < n; i++) {
            if (adj[perm[i-1]][perm[i]] == 0) {
                found_path = false;
                break;
            }
        }
        if (found_path) return true;
    } while (next_permutation(perm.begin(), perm.end()));
    return false;
}

void next_permutation() {
    int i = n-2;
    while (i >= 0 && perm[i] >= perm[i+1]) i--;
    if (i < 0) { // already last permutation
        for (int j = 0; j < n; j++) perm[j] = j;
    } else {
        int j = n-1;
        while (perm[j] <= perm[i]) j--;
        swap(perm[i], perm[j]);
        reverse(perm.begin()+i+1, perm.end());
    }
}

int main() {
    cin >> n >> m;
    adj.resize(n, vector<int>(n, 0));
    perm.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; // subtract 1 to convert to 0-based indexing
        adj[u][v] = adj[v][u] = 1;
    }
    for (int i = 0; i < n; i++) perm[i] = i;
    do {
        bool found_path = true;
        for (int i = 1; i < n; i++) {
            if (adj[perm[i-1]][perm[i]] == 0) {
                found_path = false;
                break;
            }
        }
        if (found_path) {
            cout << "YES\n";
            return 0;
        }
        next_permutation();
    } while (true);
    cout << "NO\n";
    return 0;
}
