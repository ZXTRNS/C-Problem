#include <stdio.h>

char S[101];
int A;


int main()
{
    scanf("%100[^\n]", S);
    scanf("%d", &A);
    
    printf("%s\n", S);
    printf("%d\n", A);

    return 0;
}
