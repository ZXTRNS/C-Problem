#include <stdio.h>

int pacmon(char O [101][101], int U, int Y){
    
    int food = 0;
    
    for (int P = 0; P < U; P++){
        for (int J = 0; J < Y; J++){
            if (O [P][J] == 'P'){
                
                //Jalanan
                if (O [P+1][J] == '.'){
                    O [P+1][J] = 'P';
                }
                
                if (O [P-1][J] == '.'){
                    O [P-1][J] = 'P';
                }
                
                if (O [P][J+1] == '.'){
                    O [P][J+1] = 'P';
                }
                
                if (O [P][J-1] == '.'){
                    O [P][J-1] = 'P';
                }
                
                //Makanan
                if (O [P+1][J] == '*'){
                    food += 1;
                    O [P+1][J] = 'P';
                }
                
                if (O [P-1][J] == '*'){
                    food += 1;
                    O [P-1][J] = 'P';
                }
                
                if (O [P][J+1] == '*'){
                    food += 1;
                    O [P][J+1] = 'P';
                }
                
                if (O [P][J-1] == '*'){
                    food += 1;
                    O [P][J+1] = 'P';
                }
                
            }
            
        }
    }
    return food;
}

int main()
{
    int T, A, B, count;
    char C [101][101];
    scanf("%d", &T);
    for (int i = 1; i <= T; i++){
        scanf("%d %d", &A, &B);
        
        for (int P = 0; P < A; P++){
            for (int J = 0; J < B; J++){
                scanf("%c", &C[P][J]);
            }
        }
        
        count = pacmon(C, A, B);
        printf("Case #%d: %d\n", i ,count);
        
        
    }
    
    
    

    return 0;
}