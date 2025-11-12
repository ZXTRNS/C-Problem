#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);
        int arr[N];

        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        printf("Case #%d:", t);
        for (int i = N - 1; i >= 0; i--) {
            printf(" %d", arr[i]);
        }
        printf("\n");
    }

    return 0;
}

