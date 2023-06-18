#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int array[N];

    for(int i=0; i<N; i++){
        array[i] = i+1;
    }

    for(int k=2; k<N; k++){
        int temp = array[k];
        array[k] = array[k/2];
        array[k/2] = temp;
    }

    for(int i=0; i<N; i++){
        printf("%d ", array[i]);
    }

    return 0;
}
