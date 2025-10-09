#include <stdio.h>

int main()
{
    int T,K,N,M;
    int x;
    int C[1001];
    
    scanf("%d", &T);
    for (x = 0; x<T; x++){
        scanf("%d %d %d", &K, &N, &M);
        
        if (K>(N+M)){
        	C[x] = 0;
		}
		else{
			C[x] = 1;
		}
        
    }
    
    for (x = 0; x<T; x++){
        printf("Case #%d: %s\n", x+1, (C[x] == 1)? "yes": "no");
    }
    

    return 0;
}
