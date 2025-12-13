#include <stdio.h>
#include <string.h>

int main() {
    char table[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int indexTable[128];

    // initialize all to -1
    for (int i = 0; i < 128; i++) indexTable[i] = -1;

    // map each char in table to its index
    for (int i = 0; i < 62; i++) {
        indexTable[(int)table[i]] = i;
    }

    int T;
    scanf("%d", &T);
    getchar();  // consume newline

    for (int tc = 1; tc <= T; tc++) {
        char S[600];
        fgets(S, sizeof(S), stdin);

        // remove newline if exists
        int len = strlen(S);
        if (S[len - 1] == '\n') S[len - 1] = '\0';

        printf("Case #%d: ", tc);

        for (int i = 0; S[i] != '\0'; i++) {
            int idx = indexTable[(int)S[i]];  

            if (idx == -1) {
                // not in table → print as-is
                putchar(S[i]);
            } else {
                // shift by +3 circularly
                putchar(table[(idx + 3) % 62]);
            }
        }

        putchar('\n');
    }

    return 0;
}
