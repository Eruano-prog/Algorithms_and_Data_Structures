#include <iostream>
using std::cin;
using std::cout;

int main() {
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    bool A = true;
    for (int i = 0; i < n; ++i) {
        if(2*i + 2 < n){
            A = A & (arr[i] <= arr[2 * i + 1]) & (arr[i] <= arr[2 * i + 2]);
        }
    }
    if(A){
        cout << "YES" << std::endl;
    }
    else{
        cout << "NO" << std::endl;
    }

    return 0;
}
