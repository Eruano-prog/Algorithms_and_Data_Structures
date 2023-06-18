#include <iostream>
using std::cin;
using std::cout;
using std::endl;

bool check(int* value, int* left, int* right, int N, int previous){
    bool l;
    bool r;

    if (left[N] != 0 && value[left[N]] < value[N] && value[left[N]] > previous){
        l = check(value, left, right, left[N], value[N]);
    }
    else{
        return false;
    }
    if (right[N] != 0 && value[right[N]] < value[N] && value[right[N]] > previous){
        r = check(value, left, right, right[N], value[N]);
    }
    else{
        return false;
    }
    return r&&l;
}

int main() {

    int n;
    cin >> n;

    int left[n];
    int right[n];

    int value[n];
    for (int i = 0; i < n; ++i) {
        cin >> value[i];
        cin >> left[i];
        cin >> right[i];
    }

    bool l, r;
    if (left[0] != 0 && value[0] < value[left[0]]){
        l = check(value, left, right, left[0], value[0]);
    }

    if (right[0] != 0 && value[0] > value[right[0]]){
        r = check(value, left, right, right[0], value[0]);
    }

    if (r && l){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}
