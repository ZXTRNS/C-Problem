#include <stdio.h>
#include <string.h>

#define MAX 1010
#define LEN 2005  // max length of a name (safe buffer)

char names[MAX][LEN];

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int N;
        scanf("%d", &N);

        for (int i = 0; i < N; i++) {
            scanf("%s", names[i]);
        }

        // Find minimum length among all names
        int minlen = strlen(names[0]);
        for (int i = 1; i < N; i++) {
            int l = strlen(names[i]);
            if (l < minlen) minlen = l;
        }

        // ----------- LCP -----------
        char prefix[LEN] = {0};
        int plen = 0;

        for (int i = 0; i < minlen; i++) {
            char c = names[0][i];
            int ok = 1;
            for (int j = 1; j < N; j++) {
                if (names[j][i] != c) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) break;
            prefix[plen++] = c;
        }
        prefix[plen] = '\0';

        // ----------- LCS -----------
        char suffix[LEN] = {0};
        int slen = 0;

        for (int k = 1; k <= minlen; k++) {
            char c = names[0][strlen(names[0]) - k];
            int ok = 1;
            for (int j = 1; j < N; j++) {
                if (names[j][strlen(names[j]) - k] != c) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) break;
            suffix[slen++] = c;
        }
        suffix[slen] = '\0';

        // Reverse suffix because we built it backwards
        for (int i = 0; i < slen/2; i++) {
            char tmp = suffix[i];
            suffix[i] = suffix[slen - 1 - i];
            suffix[slen - 1 - i] = tmp;
        }

        // Output format
        printf("Case #%d: %s%s\n", tc, prefix, suffix);
    }

    return 0;
}
