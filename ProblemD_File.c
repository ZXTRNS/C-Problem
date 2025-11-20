#include <stdio.h>
#include <string.h>

typedef struct {
    char from;
    char to;
} Rule;

int main() {
    freopen("testdata.in", "r", stdin);

    int T;
    if (scanf("%d", &T) != 1) return 0;

    for (int t = 0; t < T; t++) {
        char X[105];
        scanf("%s", X);

        int N;
        scanf("%d", &N);

        int sourceUsed[26] = {0};
        
        Rule rules[26]; 
        int ruleCount = 0;

        for (int i = 0; i < N; i++) {
            char src, dst;
            scanf(" %c %c", &src, &dst);
            
            if (!sourceUsed[src - 'A']) {
                sourceUsed[src - 'A'] = 1;
                rules[ruleCount].from = src;
                rules[ruleCount].to = dst;
                ruleCount++;
            }
        }

        for (int i = 0; i < ruleCount; i++) {
            char f = rules[i].from;
            char to = rules[i].to;
            
            for (int j = 0; X[j] != '\0'; j++) {
                if (X[j] == f) {
                    X[j] = to;
                }
            }
        }

        int counts[26] = {0};
        for (int j = 0; X[j] != '\0'; j++) {
            counts[X[j] - 'A']++;
        }

        for (int j = 0; j < 26; j++) {
            if (counts[j] > 0) {
                printf("%c %d\n", j + 'A', counts[j]);
            }
        }
    }

    return 0;
}