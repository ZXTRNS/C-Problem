#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N, M, Q;
        scanf("%d %d %d", &N, &M, &Q);

        int pattern[55][55] = {0};
        int lamp[55] = {0};

        // Read friends' patterns
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                scanf("%d", &pattern[i][j]);
            }
        }

        // Process visit sequence
        for (int q = 0; q < Q; q++) {
            int friend_id;
            scanf("%d", &friend_id);
            for (int j = 1; j <= M; j++) {
                if (pattern[friend_id][j] == 1)
                    lamp[j] ^= 1; // toggle (0→1, 1→0)
            }
        }

        // Output results
        printf("Case #%d:\n", t);
        for (int j = 1; j <= M; j++) {
            if (lamp[j])
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    return 0;
}