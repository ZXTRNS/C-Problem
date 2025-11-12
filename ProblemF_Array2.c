#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    getchar(); // consume newline
    
    for (int t = 1; t <= T; t++) {
        char S[100005];
        scanf("%s", S);

        int freq[26] = {0};
        int distinct = 0;

        for (int i = 0; S[i] != '\0'; i++) {
            int idx = S[i] - 'a';
            if (!freq[idx]) {
                freq[idx] = 1;
                distinct++;
            }
        }

        printf("Case #%d: %s\n", t, (distinct % 2 == 0) ? "Yay" : "Ewwww");
    }

    return 0;
}
