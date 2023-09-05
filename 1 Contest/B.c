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

    int last = ar[N-1];
    for(int i=N-1; i>0; i--){
        ar[i] = ar[i-1];
    }
    ar[0] = last;

    for (int i=0; i<N; i++){
        printf("%d ", ar[i]);
    }

    return 0;
}
