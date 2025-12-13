#include <stdio.h>

int main()
{
    FILE *baca = fopen("testdata.in", "r");
    int A, B;
    
    
    fscanf(baca, "%d %d", &A, &B);
    
    A = A + B;
    
    printf("%d\n", A);

    return 0;
}
