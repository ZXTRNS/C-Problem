#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char NIM[20], zona;
    char list[40] = {"abcdefghijklmnopqrstuvwxyz"};
    char list2[10] = {"1234567890"};
    char tahunLegal[6][10] = {"2020", "2021", "2022", "2023", "2024", "2025"};
    int T, biayaDasar;
    
    scanf("%d", &T); getchar();
    for (int i = 1; i <= T; i++){

        //bagian input
        fgets(NIM, sizeof(NIM), stdin);
        NIM[strcspn(NIM, "\n")] = '\0';
        for (int r = 0; NIM[r]; r++){
            NIM[r] = tolower(NIM[r]);
        }
        
        //bagian fakultas
        char* fakultas = strtok(NIM, "-");
        int cekFakultas = strspn(fakultas, list);
        if (cekFakultas != 2 && cekFakultas != 3){
            printf("NIM #%d: TIDAK VALID 0\n", i);
        }
        else{

            //bagian tahun
            char* tahun = strtok(NULL, "-");
            int tahunValid = 0;
            for (int u = 0; u < 6; u++){
                int cekTahun = strcmp(tahun, tahunLegal[u]);
                if (cekTahun == 0){
                    tahunValid = 1;
                }
            }

            if (tahunValid == 0){
                printf("NIM #%d: TIDAK VALID 0%s\n", i, tahun);
            }
            else{
                
                //bagian nomer
                char* nomer = strtok(NULL, "-");
                int cekNomer = strspn(nomer, list2);
                if (cekNomer != 3){
                    printf("NIM #%d: TIDAK VALID 0\n", i);
                }
                else{
                    
                    //tambahan
                    if (strcmp(fakultas, "ft") == 0|| strcmp(fakultas, "fte") == 0){
                        biayaDasar = 150000;
                        zona = 'A';
                    }
                    else if (strcmp(fakultas, "feb") == 0){
                        biayaDasar = 175000;
                        zona = 'B';
                    }
                    else if (strcmp(fakultas, "fh") == 0){
                        biayaDasar = 170000;
                        zona = 'C';
                    }
                    else{
                        biayaDasar = 140000;
                        zona = 'D';
                    }

                    if (strcmp(tahun, "2022") == 0){
                        biayaDasar = biayaDasar - 10000;
                    }

                    if (nomer[0] == '1' || nomer[0] == '3' || nomer[0] == '5' || nomer[0] == '7' || nomer[0] == '9'){
                        biayaDasar = biayaDasar + 5000;
                    }
    
                    printf("NIM #%d: ZONA-%c %d\n", i, zona, biayaDasar);
                }
            }
        }
    }

    return 0;
}