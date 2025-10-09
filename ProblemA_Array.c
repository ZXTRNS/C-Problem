#include <stdio.h>

int main()
{
    int N,Q,hargaI;
    long long C[101],hargaBaru;
    
    
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%lld", &C[i]);
    }
    
    scanf("%d", &Q);
    for(int i = 1; i <= Q; i++){
        scanf("%d %lld", &hargaI, &hargaBaru);
        C[hargaI - 1] = hargaBaru;
        
        printf("Case #%d:", i);
        for(int i = 0; i < N; i++){
            printf(" %lld", C[i]);
        }
        printf("\n");
        
    }
    

    return 0;
}