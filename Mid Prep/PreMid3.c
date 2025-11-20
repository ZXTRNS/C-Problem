#include <stdio.h>
#include <ctype.h>

int kerja(char username[200], int huruf, int digit, int spesial){

    for(int i = 0; username[i]; i++){
        if (isalpha(username[i]) != 0){
            huruf++;
        }
        else if (isdigit(username[i]) != 0){
            digit++;
        }
        else spesial++;
    }

    return huruf, digit, spesial;
}

int main() {
    char username[200];

    scanf("%[^\n]", &username);
    fflush(stdin);

    int i = 0;
    int huruf = 0, digit = 0, spesial = 0;
    char c;

    kerja(username, huruf, digit, spesial);

    printf("Analisis: Huruf=%d, Digit=%d, Spesial=%d", huruf, digit, spesial);

    getchar();

    return 0;
}