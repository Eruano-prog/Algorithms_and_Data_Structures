#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int ask(int* left, int* right, int N){
    int l;
    int r;

    if (left[N] == 0 && right[N] == 0){
        return 1;
    }
    else if (left[N] == 0 && right[N] != 0){
        return ask(left, right, right[N]-1) + 1;
    }
    else if (left[N] != 0 && right[N] == 0){
        return ask(left, right, left[N]-1) + 1;
    }
    else {
        l = ask(left, right, left[N]-1);
        r = ask(left, right, right[N]-1);
        if (l > r){
            return l+1;
        }
        else{
            return r+1;
        }
    }
}

int main() {

    int n;
    cin >> n;

    if (n == 0){
        cout << 0;
    }
    else {
        int left[n];
        int right[n];

        int num;
        for (int i = 0; i < n; ++i) {
            cin >> num;
            cin >> left[i];
            cin >> right[i];
        }

        cout << ask(left, right, 0);
    }

    return 0;
}
