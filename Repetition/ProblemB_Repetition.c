#include <stdio.h>

int main()
{
    
    int T;
    float a,b,c,d;
    double C[4];
    
    scanf("%d", &T); getchar();
    for(int i = 0; i < T; i++){
        scanf("%f %f %f %f", &a, &b, &c, &d); getchar();
        double hasil = ((a + b)*2) + (d/2) + (c * 4/3);
        C[i] = hasil;
    }
    
    for(int i = 0; i < T; i++){
        printf("%.2lf\n", C[i]);
    }

    return 0;
}