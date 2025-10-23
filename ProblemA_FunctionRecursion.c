#include <stdio.h>

int fibo(int n){
    unsigned long long O;
    O = n;
    
    if (n == 0){
        return 1;
    }
    
    if (n == 1){
        return 1;
    }
    
    return 1 + fibo(O-1) + fibo(O-2);
}

int main()
{
    int T, A, count;
    
    scanf("%d", &T);
    for (int i = 1; i <= T; i++){
        scanf("%d", &A);
        count = fibo(A);
        printf("Case #%d: %d\n", i, count);
    }

    return 0;
}