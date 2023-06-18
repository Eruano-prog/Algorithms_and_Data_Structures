#include <iostream>

using std::cout;
using std::cin;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    int drawings[N][M];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> drawings[i][j];
        }
    }

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int x3, y3, x4, y4;
        cin >> x3 >> y3 >> x4 >> y4;

        if (x1 == x3 and y1 == y3 and x2 == x4 and y2 == y4){
            cout << "YES\n";
            continue;
        }

        long long hash_1 = 0;
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                hash_1 = hash_1*6 + drawings[i - 1][j - 1];
            }
        }

        long long hash_2 = 0;
        for (int i = x3; i <= x4; i++) {
            for (int j = y3; j <= y4; j++) {
                hash_2 = hash_2*6 + drawings[i - 1][j - 1];
            }
        }

        if (hash_1 == hash_2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
