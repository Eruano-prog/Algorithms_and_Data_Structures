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

    int id = 0;
    for(int k = 0; k<2; k++) {
        int min_n = ar[0];
        for (int i = 1; i < N; i++) {
            if (ar[i] < min_n) {
                min_n = ar[i];
                id = i;
            }
        }
        printf("%d ", min_n);
        ar[id] = 2000000000;

    }


    return 0;
}
