integer = int(input())
print(integer%10)#include <stdio.h>

void Merge(int* array, int left, int mid, int right){
    int it1 = 0;
    int it2 = 0;
    int result[right-left];

    while((left+it1 < mid) & (mid + it2 < right)){
        if(array[left+it1] < array[mid+it2]){
            result[it1+it2] = array[left+it1];
            it1++;
        }
        else{
            result[it1+it2] = array[mid+it2];
            it2++;
        }
    }

    while(left+it1 < mid){
        result[it1+it2] = array[left+it1];
        it1++;
    }

    while(mid + it2 < right){
        result[it1+it2] = array[mid+it2];
        it2++;
    }

    for(int i=0; i<it1+it2; i++){
        array[left+i] = result[i];
    }
}



void MergeSort(int* array, int left, int right){
    if(left+1 >= right){
        return;
    }
    int mid = (left + right)/2;
    MergeSort(array, left, mid);
    MergeSort(array, mid, right);
    Merge(array, left, mid, right);
}


int main() {

    int K;
    scanf("%d", &K);

    int array[K];

    for(int i=0; i<K; i++){
        scanf("%d", &array[i]);
    }

    MergeSort(array, 0, K);

    for(int i=0; i<K; i++){
        printf("%d ", array[i]);
    }

    return 0;
}
