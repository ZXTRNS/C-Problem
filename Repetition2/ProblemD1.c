#include <stdio.h>
#include <string.h>

int main() {
    int T;
    char S[1005];

    scanf("%d", &T); getchar();

    for (int t = 1; t <= T; t++) {
        
        scanf("%s", S); getchar();
        
        //menghapus newline character di akhir kalimat
        size_t PanjangString = strlen(S);
        if (S[PanjangString - 1] == '\n') {
            S[PanjangString - 1] = '\0';
            PanjangString--;
        }
        
        int Palindrome = 1;
        
        //disini dicek satu persatu karakter di string (Palindrome atau ga)
        for (int j = 0; j < PanjangString/2 ; j++) {
            if (S[j] != S[PanjangString - j - 1]) {
                Palindrome = 0; // ketemu perbedaan
                break;
            }
        }
        
        if (Palindrome == 0){
            printf("Case #%d: Nah, it’s not a palindrome\n", t);
        }
        else{
            printf("Case #%d: Yay, it’s a palindrome\n", t);
        }
        
    }

    return 0;
}