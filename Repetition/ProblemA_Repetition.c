#include <stdio.h>

int main() {
    int T; 
    scanf("%d", &T); 
    for (int i = 0; i < T; i++) {
        int A; 
        scanf("%d", &A);

        float R = (4.0/5.0) * A;       
        float F = (9.0/5.0) * A + 32; 
        float K = A + 273;             
        printf("%.2f %.2f %.2f\n", R, F, K);
    }

    return 0;
}