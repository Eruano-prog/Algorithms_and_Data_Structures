#include <stdio.h>

void swap(int* pF, int* pS){
    int key = *pF;
    *pF = *pS;
    *pS = key;
}

void QuickSort(int* array, int left, int right){
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
    int arr1[N];
    for(int i=0; i<N; i++){
        scanf("%d", &arr1[i]);
    }

    int K;
    scanf("%d", &K);
    int arr2[K];
    for(int i=0; i<K; i++){
        scanf("%d", &arr2[i]);
    }


    QuickSort(arr1, 0, N-1);
    QuickSort(arr2, 0, K-1);

    int it1 = 0, it2 = 0, flag = 1;
    while (it1<N | it2<K){
        while(arr1[it1] == arr1[it1+1]){
            it1++;
        }
        while(arr2[it2] == arr2[it2+1]){
            it2++;
        }
        if(arr1[it1] == arr2[it2]){
            it1++;
            it2++;
        }
        else{
            flag = 0;
            break;
        }
    }
    flag == 1 ? printf("YES") : printf("NO");
    return 0;
}
