#include <stdio.h>

int fibo(int n){
    unsigned long long O;
    O = n;
    
    if (n == 0){
        return 0;
    }
    
    if (n == 1){
        return 1;
    }
    
    if (n == 2){
        return 1;
    }
    return fibo(O-1) + fibo(O-3);
}

int main()
{
    int A, count;
    
    scanf("%d", &A);
    count = fibo(A);
    printf("%d\n", count);

    return 0;
}
