#include <stdio.h>


struct Partic{
    int ID;
    int point;
};


int main() {

    int K;
    scanf("%d", &K);

    struct Partic array[K];

    for(int i=0; i<K; i++){
        scanf("%d %d", &array[i].ID, &array[i].point);
    }

    for(int i=1; i < K; i++){
        struct Partic key = array[i];
        int j = i-1;
        while(j > -1 & array[j].ID > key.ID){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }

    for(int i=1; i < K; i++){
        struct Partic key = array[i];
        int j = i-1;
        while(j > -1 & array[j].point < key.point){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }

    for(int i=0; i<K; i++){
        printf("%d %d\n", array[i].ID, array[i].point);
    }

    return 0;
}
