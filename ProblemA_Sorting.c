#include <stdio.h>
#include <string.h>

int main()
{
    int T, N;
    
    scanf("%d", &T); getchar();
    for (int i = 1; i <= T; i++){
        
        int nomor[51];
        char nama[51][51], data[51][51];
        int temp = 0, y = 0, u = 0;
        char temp2[51];
        
        scanf("%d", &N); getchar();
        for (int j = 0; j < N; j++){
            scanf("%[^#]#%d", &nama[j], &nomor[j]); getchar();
        }
        
        // //token (dipisah pisah)
        // for (int j = 0; j < N; j++){
        //     char* token = strtok(data[j],"#");
        //     strcpy(nama[y++], token);
        //     //ganti dari string ke int
        //     token = strtok(NULL, "#");
        //     strcpy(temp2, token);
        //     sscanf(temp2, "%d", &nomor[u++]);
        // }
        
        //bubble sorting
        for (int p = 0; p < N; p++){
            for (int q = 0; q < (N-p-1); q++){
                if (nomor[q] > nomor[q+1] || (nomor[q] == nomor[q+1] && strcmp(nama[q], nama[q+1]) < 0)){
                    temp = nomor[q];
                    nomor[q] = nomor[q+1];
                    nomor[q+1] = temp;
                    
                    strcpy(temp2, nama[q]);
                    strcpy(nama[q], nama[q+1]);
                    strcpy(nama[q+1], temp2);
                }
            }
        }
        
        printf("Case #%d:\n", i);
        for (int j = N - 1; j >= 0; j--){
            printf("%s - %d\n", nama[j], nomor[j]);
        }
    }

    return 0;
}
