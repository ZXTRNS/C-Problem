#include <stdio.h>
#include <string.h>

int main()
{
    int T,N;
    long long A[105][105];
    long long P[105];
    
    scanf("%d", &T); getchar;
    for(int x = 1; x <= T; x++){
        
        scanf("%d", &N); getchar;
        
        //scan matrix
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
               scanf("%lld", &A[i][j]); getchar;
            }
        }
        
        printf("Case #%d:", x);
        memset(P, 0, sizeof(P));
        
        //ngitung
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
               P[i] += A[j][i];
            }
            printf(" %lld", P[i]);
        }
        
        printf("\n");
        
    }

    return 0;
}
