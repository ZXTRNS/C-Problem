#include <stdio.h>

int main()
{
    int T,N;
    unsigned long long O[95];
    
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        scanf("%d", &N);
        O[0] = 0;
        O[1] = 1;
        
        for(int i = 2; i < N; i++){
            O[i] = O[i-1] + O[i-2];
        }
        printf("Case #%d: %llu\n", i, O[N-1]);
        
    }
    

    return 0;
}