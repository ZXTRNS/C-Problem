#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N;
        scanf("%d", &N);

        int A[55][55], B[55][55], C[55][55];
        int temp[55][55], result[55][55];

        // Read matrix A
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                scanf("%d", &A[i][j]);

        // Read matrix B
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                scanf("%d", &B[i][j]);

        // Read matrix C
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                scanf("%d", &C[i][j]);

        // Multiply A and B => store in temp
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                temp[i][j] = 0;
                for (int k = 0; k < N; k++) {
                    temp[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        // Multiply temp and C => store in result
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result[i][j] = 0;
                for (int k = 0; k < N; k++) {
                    result[i][j] += temp[i][k] * C[k][j];
                }
            }
        }

        // Print output
        printf("Case #%d:\n", t);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                printf("%d", result[i][j]);
                if (j < N - 1) printf(" ");
            }
            printf("\n");
        }
    }

    return 0;
}