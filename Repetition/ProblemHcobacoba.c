#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    long long x = *(long long*)a;
    long long y = *(long long*)b;
    return (x > y) - (x < y);
}

int main() {
    int T;
    scanf("%d", &T);

    for (int x = 1; x <= T; x++) {
        long long S[30];
        for (int i = 0; i < 25; i++) {
            scanf("%lld", &S[i]); getchar();
        }

        qsort(S, 25, sizeof(long long), cmp);

        long long ans[5];
        int idx = 0;

        // pick the 5 numbers that appear only once (the doubles 2*Mi)
        for (int i = 0; i < 25; i++) {
            if ((i == 0 || S[i] != S[i-1]) && (i == 24 || S[i] != S[i+1])) {
                ans[idx++] = S[i] / 2;
            }
        }

        qsort(ans, 5, sizeof(long long), cmp);

        printf("Case #%d:", x);
        for (int i = 0; i < 5; i++) {
            printf(" %lld", ans[i]);
        }
        printf("\n");
    }
    return 0;
}

