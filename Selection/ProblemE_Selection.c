#include <stdio.h>

int main()
{
    int D,T,S;
    
    scanf("%d %d %d", &D, &S, &T);
    
    if (D > S && D > T){
        printf("Daging\n");
        if (S > T){
            printf("Sayur\n");
            printf("Telur\n");
        }
        else{
            printf("Telur\n");
            printf("Sayur\n");
        }
    }
    else if (S > D && S > T){
        printf("Sayur\n");
        if (D > T){
            printf("Daging\n");
            printf("Telur\n");
        }
        else{
            printf("Telur\n");
            printf("Daging\n");
        }
    }
    else{
        printf("Telur\n");
        if (D > S){
            printf("Daging\n");
            printf("Sayur\n");
        }
        else{
            printf("Sayur\n");
            printf("Daging\n");
        }
    }

    return 0;
}
