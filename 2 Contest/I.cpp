#include <stdio.h>

void swap(int* pF, int* pS){
    int key = *pF;
    *pF = *pS;
    *pS = key;
}

void QuickSort(int array[], int left, int right){
    int i = left;
    int j = right;
    int p = array[(left+right)/2];

    while(i <= j){
        while(array[i] < p){
            i++;
        }
        while(array[j] > p){
            j--;
        }
        if(i <= j) {
            swap(&array[i++], &array[j--]);
        }

    }
    if(left<j){
        QuickSort(array, left, j);
    }
    if(right>i){
        QuickSort(array, i, right);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    int array[N];
    for(int i=0; i<N; i++){
        scanf("%d", &array[i]);
    }
    QuickSort(array, 0, N-1);
    for(int i=0; i<N; i++){
        printf("%d ", array[i]);
    }


    return 0;
}
