#include <stdio.h>

int main() {
    int T, N;
    long long C[1005];
    
    scanf("%d", &T);
    for (int x = 0; x < T; x++) {
        scanf("%d", &N);
        
        long long total = 0;
        for (int i = 0; i < N; i++) {
            scanf("%lld", &C[i]);
            total += C[i];
        }
        
        printf("Case #%d: %lld\n", x + 1, total);
    }
    
    return 0;
}