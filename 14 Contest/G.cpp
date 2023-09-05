#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> drawings(N, vector<int>(M));

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

        vector<vector<int>> piece1(x2 - x1 + 1, vector<int>(y2 - y1 + 1));
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                piece1[i - x1][j - y1] = drawings[i - 1][j - 1];
            }
        }

        int x3, y3, x4, y4;
        cin >> x3 >> y3 >> x4 >> y4;

        vector<vector<int>> piece2(x4 - x3 + 1, vector<int>(y4 - y3 + 1));
        for (int i = x3; i <= x4; i++) {
            for (int j = y3; j <= y4; j++) {
                piece2[i - x3][j - y3] = drawings[i - 1][j - 1];
            }
        }

        if (piece1 == piece2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
