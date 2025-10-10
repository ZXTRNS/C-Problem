#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int views[105];
    int prefix[105];
    prefix[0] = 0;

    // Read daily views and build prefix sum
    for (int i = 1; i <= N; i++) {
        scanf("%d", &views[i]);
        prefix[i] = prefix[i - 1] + views[i];
    }

    int Q;
    scanf("%d", &Q);

    for (int i = 1; i <= Q; i++) {
        int A, B;
        scanf("%d %d", &A, &B);

        int total = prefix[B] - prefix[A - 1];
        printf("Case #%d: %d\n", i, total);
    }

    return 0;
}