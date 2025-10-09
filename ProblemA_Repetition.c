#include <stdio.h>


// void transpose(int matrix[105][105], int rows, int cols) {
//     int i, j;
//     int transposed[105][105];
    
//     for (i = 0; i < rows; i++) {
//         for (j = 0; j < cols; j++) {
//             transposed[j][i] = matrix[i][j];
//         }
//     }
// }



int main()
{
    
    int T,N;
    int A[105][105];
    int P[105];
    
    scanf("%d", &T);
    for (int x = 1; x <= T; x++){
        scanf("%d", &N);
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &A[i][j]);
            }
        }
        
        printf("Case #%d =", x);
        
        for (int j = 0; j < N; j++) {
            for (int i = 0; i < N; i++) {
                P[j] += A[i][j];
            }
            printf(" %d", P[j]);
        }
        printf("\n");
        
    }

    return 0;
}