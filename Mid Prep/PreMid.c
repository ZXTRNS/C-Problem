#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char positive[7][10] = {"bagus", "suka", "puas", "cepat", "keren", "terbaik", "mantap"};
    char negative[8][10] = {"kecewa", "rusak", "lambat", "jelek", "parah", "lama", "rugi", "menipu"};
    char Ui[200];
    char d[] = " ,.!";
    int T;
    
    scanf("%d", &T);
    getchar();
    for (int i = 1; i <= T; i++){
        int positip = 0, negatip = 0;
        
        fgets(Ui, sizeof(Ui), stdin);
        Ui[strcspn(Ui, "\n")] = '\0';
        for (int k = 0; Ui[k]; k++){
            Ui[k] = tolower(Ui[k]);
        }
        char* kontol = strtok(Ui, d);

        while(kontol != NULL){

            for (int o = 0; o < 7; o++){
                if (strcmp(kontol, positive[o]) == 0){
                    positip++;
                }
            }
            for (int o = 0; o < 8; o++){
                if (strcmp(kontol, negative[o]) == 0){
                    negatip++; 
                }
            }

            kontol = strtok(NULL, d);
        }

        printf("Ulasan #%d: %s (Positif: %d, Negatif: %d)\n", i, (positip == negatip)? "NETRAL": (positip < negatip)? "NEGATIF": "POSITIF", positip, negatip);
    }

    return 0;
}