#include <iostream>
using std::cin;
using std::cout;

int Left_Bin_Search(int* mas,int right, int x){
    int left = 0;
    while(right > left){
        int mid = (left + right) / 2;
        if (mas[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid;
        };
    }

    if (mas[left] == x){
        return left + 1;
    }
    else{
        return -1;
    }
}

int Right_Bin_Search(int* mas,int right, int x){
    int left = 0;
    while(right > left){
        int mid = (left + right) / 2;
        if (mas[mid] > x) {
            right = mid;
        }
        else {
            left = mid + 1;
        };
    }

    if (mas[right - 1] == x){
        return right;
    }
    else{
        return -1;
    }
}


int main() {
    int N;
    cin >> N;

    int arr[N];
    for (int i = 0; i < N; ++i) {

        cin >> arr[i];
    }

    int M;
    cin >> M;

    int ar[M];
    for (int i = 0; i < M; ++i) {
        cin >> ar[i];
    }

    for (int i = 0; i < M; ++i) {
        cout << Left_Bin_Search(arr, N, ar[i]) << ' ' << Right_Bin_Search(arr, N, ar[i]) << std::endl;
    }


    return 0;
}
