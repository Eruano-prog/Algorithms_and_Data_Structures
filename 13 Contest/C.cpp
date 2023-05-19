#include <iostream>

using std::cout;
using std::cin;

int Hash(int* arr, int N){
    int hash = 0;
    int xors = 0;
    for (int i = 0; i < N; ++i) {
        xors = xors xor arr[i];
        hash = (hash + arr[i] * 123) % 1000007;
    }
    return hash xor xors;
}

int main(){
    int N;
    cin >> N;
    int S1[N], S2[N];

    for (int i = 0; i < N; ++i) {
        cin >> S1[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> S2[i];
    }

    if (Hash(S1, N) == Hash(S2, N)) {
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}