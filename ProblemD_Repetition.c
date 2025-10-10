#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        char S[105];
        scanf("%d", &N);
        scanf("%s", S);

        int countL = 0, countB = 0;
        for (int i = 0; i < N; i++) {
            if (S[i] == 'L') countL++;
            else if (S[i] == 'B') countB++;
        }

        if (countL > countB) printf("Lili\n");
        else if (countB > countL) printf("Bibi\n");
        else printf("None\n");
    }
    return 0;
}
