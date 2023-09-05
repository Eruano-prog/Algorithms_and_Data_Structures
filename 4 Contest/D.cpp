#include <iostream>
using std::cin;
using std::cout;



int main() {

    int n, N, k;

    cin >> n >> N >> k;

    char arr[n][N];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < k; ++i) {
        int raz = N - i - 1;

        int count[30];

        for (int i = 0; i < 30; ++i) {
            count[i] = 0;
        }

        for (int i = 0; i < n; ++i) {
            count[arr[i][raz] - 97]++;
        }

        for (int i = 1; i < 30; ++i) {
            count[i] += count[i - 1];
        }

        char result[n][N];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < N; ++j) {
                result[i][j] = NULL;
            }
        }

        int ind;
        for (int i = n - 1; i >= 0; i--) {
            ind = count[arr[i][raz] - 97]-1;

            for (int j = 0; j < N; j++) {
                result[ind][j] = arr[i][j];
            }

            count[arr[i][raz] - 97]--;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < N; ++j) {
                arr[i][j] = result[i][j];
            }
        }

    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << arr[i][j];
        }
        cout << '\n';
    }
    return 0;
}
