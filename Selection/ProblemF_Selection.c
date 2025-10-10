#include <stdio.h>

int main()
{
    int x,y,k;
    
    scanf("%d %d %d", &x, &y, &k);
    
    int total1 = k-x;
    int total2 = y-k;
    if (total1==total2 && total1 >= 0){
        printf("%d\n",total1);
    }
    else{
        printf("-1\n");
    }

    return 0;
}