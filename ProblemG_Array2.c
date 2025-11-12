#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);

        long long X[10000], Y[10000];
        for (int i = 0; i < N; i++) scanf("%lld", &X[i]);
        for (int i = 0; i < N; i++) scanf("%lld", &Y[i]);

        int failed = 0;
        for (int i = 0; i < N; i++) {
            if (X[i] < Y[i]) failed++;
        }

        printf("Case #%d: %d\n", t, failed);
    }

    return 0;
}
