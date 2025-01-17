#include <iostream>
using std::cin;
using std::cout;

void swap(int* pF, int* pS){
    int key = *pF;
    *pF = *pS;
    *pS = key;
}


void heapify(int arr[], int n, int i){
    int max = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[max]) {
        max = left;
    }

    if (right < n && arr[right] > arr[max]) {
        max = right;
    }

    if (max != i){
        swap(&arr[i], &arr[max]);

        heapify(arr, n, max);
    }
}

void heapSort(int arr[], int n)
{
    for (int i=n-1; i>=0; i--){
        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}



int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    heapSort(arr, n);

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}
