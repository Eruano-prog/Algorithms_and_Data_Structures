#include <iostream>
using std::cin;
using std::cout;

void build(int pos, int &n1, int n2, int** ar, int* ans) {
    if (ar[pos][0] == 0 and ar[pos][1] == 0) {
        ans[pos] = n1;
        n1--;
        return;
    } else if (ar[pos][0] == 0 and ar[pos][1] != 0) {
        build(ar[pos][1]-1, n1, n2, ar, ans);
        ans[pos] = n1;
        n1--;
        return;
    } else if (ar[pos][0] != 0 and ar[pos][1] == 0) {
        ans[pos] = n1;
        n1--;
        build(ar[pos][0]-1, n1, n2, ar, ans);
        return;
    } else if (ar[pos][0] != 0 and ar[pos][1] != 0) {
        build(ar[pos][1]-1, n1, n2, ar, ans);
        ans[pos] = n1;
        n1--;
        build(ar[pos][0]-1, n1, n2, ar, ans);
        return;
    }
}

int main() {
    int n;
    cin >> n;

    int **ar = new int* [n];
    for (int i = 0; i < n; i++) {
        ar[i] = new int [2];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> ar[i][j];
        }
    }

    int number = n;
    int ans[n];

    build(0, number, n, ar, ans);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}