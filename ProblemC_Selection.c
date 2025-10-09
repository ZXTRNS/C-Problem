#include <stdio.h>

int main()
{
    int T,A,B;
    int x;
    int C[1001];
    
    scanf("%d", &T);
    for (x = 0; x<T; x++){
        scanf("%d %d", &A, &B);
        C[x] = (A>B)? 0: 1;
        
    }
    
    for (x = 0; x<T; x++){
        printf("Case #%d: %s\n", x+1, (C[x] == 0)? "Go-Jo": "Bi-Pay");
    }
    

    return 0;
}