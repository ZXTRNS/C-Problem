#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);

        int A[105], B[105];

        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }
        for (int i = 0; i < N; i++) {
            scanf("%d", &B[i]);
        }

        printf("Case #%d:", t);
        for (int i = 0; i < N; i++) {
            int result = A[i] - B[i];
            printf(" %d", result);
        }
        printf("\n");
    }

    return 0;
}
