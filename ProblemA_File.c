#include <stdio.h>
#include <string.h>

int main()
{
    FILE *nulis = fopen("testdata.in", "w");
    
    int N, T, i, j;
    char MP[82], S[41], membandingkan[100];
    char *bro;
    
    scanf("%d", &N); getchar();
    for (i = 0; i < N; i++){
        fgets(MP, sizeof(MP), stdin);
        MP[strcspn(MP, "\n")] = '\0';
        fprintf(nulis, "%s\n", MP);
    }
    
    fclose(nulis);
    
    scanf("%d", &T);
    for (i = 1; i <= T; i++){
        scanf("%s", S);
        
        FILE *baca = fopen("testdata.in", "r");
        int gakKetemu = 0;
        
        while (fgets(membandingkan, sizeof(membandingkan), baca)){
        	bro = strtok(membandingkan, "#");
        	
        	if (strcmp(bro, S) == 0){
        		bro = strtok(NULL, "#");
        		break;
        	}
        	else{
        		gakKetemu++;
			}
		}
		
		fclose(baca);
		
		membandingkan[strcspn(membandingkan, "\n")] = '\0';
		if (gakKetemu == N){
			printf("Case #%d: N/A", i);
		}
		else{
			printf("Case #%d: %s\n", i, bro);
		}
    }

    return 0;
}
