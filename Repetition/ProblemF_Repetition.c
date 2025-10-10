#include <stdio.h>
#include <string.h>

int main() {
    int T;
    char S[1005];

    scanf("%d", &T); getchar();

    for (int t = 1; t <= T; t++) {
        
        /**pake fgets karena scanf berhenti sampe spasi, 
        dan karena ini ada spasinya jadi sangat disarankan pake fgets**/
        fgets(S, sizeof(S), stdin); 
        
        //menghapus newline character di akhir kalimat
        size_t PanjangString = strlen(S);
        if (S[PanjangString - 1] == '\n') {
            S[PanjangString - 1] = '\0';
            PanjangString--;
        }
        
        //disini dibalik satu persatu karakter di string
        for (int i = 0, j = PanjangString - 1; i < j; i++, j--) {
            char balik = S[i];
            S[i] = S[j];
            S[j] = balik;
        }
        
        printf("Case #%d: %s\n", t, S);
    }

    return 0;
}
