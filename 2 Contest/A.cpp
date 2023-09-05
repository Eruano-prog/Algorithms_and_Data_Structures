#include <stdio.h>

int main() {
    int N;
    int index;
    int number;

    scanf("%d", &N);
    N += 1;

    int arr[N];
    for(int i=0; i<N-1; i++){
        scanf("%d", &arr[i]);
    }

    scanf("%d %d", &number, &index);

    for(int j=N+1; j>=index; j--){
        arr[j] = arr[j-1];
    }
    arr[index-1] = number;

    for(int i=0; i<N; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
