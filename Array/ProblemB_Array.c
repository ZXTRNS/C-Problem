#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);

        int A[205];
        int cool[205] = {0}; // marks whether A[i] is cool

        for (int i = 0; i < N; i++)
            scanf("%d", &A[i]);

        // check all pairs
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue; // must be different numbers
                int sum = A[i] + A[j];
                // check if this sum exists in the list
                for (int k = 0; k < N; k++) {
                    if (A[k] == sum) {
                        cool[k] = 1;
                    }
                }
            }
        }

        // count cool numbers
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (cool[i]) count++;
        }

        printf("Case #%d: %d\n", t, count);
    }

    return 0;
}