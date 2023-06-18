#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    fflush(stdin);

    int ar[N];
    for (int i=0; i<N; i++){
        int(num);
        scanf("%d", &num);
        ar[i] = num;
    }

    int count = 0;
    for(int i=1; i<N-1; i++){
        if(ar[i-1] < ar[i] & ar[i] > ar[i+1]){
            count += 1;
        }
    }
    printf("%d", count);

    return 0;
}
