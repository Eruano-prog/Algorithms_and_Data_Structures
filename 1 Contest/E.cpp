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

    int num;
    scanf("%d", &num);

    int min_dif = 3000;
    int ans = 0;

    for(int i=0; i<N; i++){
        int dif = (num-ar[i])<0? -(num-ar[i]):(num-ar[i]);
        if(dif < min_dif){
            min_dif = dif;
            ans = ar[i];
        }
    }

    printf("%d", ans);

    return 0;
}
