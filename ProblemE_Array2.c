#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    for (int t = 1; t <= T; t++) {
        int X;
        scanf("%d", &X);
        
        long long matrix[105][105];
        long long colSum[105] = {0};
        
        // Read matrix and calculate column sums
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < X; j++) {
                scanf("%lld", &matrix[i][j]);
                colSum[j] += matrix[i][j];
            }
        }
        
        // Output result
        printf("Case #%d:", t);
        for (int j = 0; j < X; j++) {
            printf(" %lld", colSum[j]);
        }
        printf("\n");
    }
    
    return 0;
}
