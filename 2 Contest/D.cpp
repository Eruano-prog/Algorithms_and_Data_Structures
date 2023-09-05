#include <stdio.h>

void InsertionSort(int* array, int N){
    for(int i=1; i < N; i++){
        int key = array[i];
        int j = i-1;
        while(j > -1 & array[j] > key){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}


int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int rafts[N * M];
    for(int i=0; i<(N*M); i++){
        scanf("%d", &rafts[i]);
    }



    int *prafts = (int *) &rafts;

    InsertionSort(prafts, N*M);

    int K;
    scanf("%d", &K);

    int mesks[K];

    for(int i=0; i<K; i++){
        scanf("%d", &mesks[i]);
    }

    int *pmesks = (int *) &mesks;
    InsertionSort(pmesks, K);

    int count = 0, i=0, j=0;

    while((i < (N*M)) & (j < K)){
        if(rafts[i] >= mesks[j]){
            count++;
            j++;
            i++;
        }
        else{
            i++;
        }
    }

    printf("%d", count);

    return 0;
}
