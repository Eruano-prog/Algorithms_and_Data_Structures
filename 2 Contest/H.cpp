#include <stdio.h>

struct Friend{
    int start;
    int end;
};

void Merge(struct Friend* array, int left, int mid, int right){
    int it1 = 0;
    int it2 = 0;
    struct Friend result[right-left];

    while((left+it1 < mid) & (mid + it2 < right)){
        if(array[left+it1].start < array[mid+it2].start){
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



void MergeSort(struct Friend* array, int left, int right){
    if(left+1 >= right){
        return;
    }
    int mid = (left + right)/2;
    MergeSort(array, left, mid);
    MergeSort(array, mid, right);
    Merge(array, left, mid, right);
}

int main() {
    int N;
    scanf("%d", &N);
    struct Friend array[N];

    for(int i=0; i<N; i++){
        scanf("%d %d", &array[i].start, &array[i].end);
    }

    MergeSort(array, 0, N);

    int res = array[0].end - array[0].start + 1;
    int max = array[0].end;

    for(int i=1; i<N; i++){
        if(array[i].start > max){
            res += array[i].end - array[i].start + 1;
            max = array[i].end;
        }
        else{
            if(array[i].end > max){
                res += array[i].end - max;
                max = array[i].end;
            }
        }
    }

    printf("%d", res);
    return 0;
}
