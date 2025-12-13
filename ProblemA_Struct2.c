#include <stdio.h>
#include <stdlib.h>

char map[105][105];
int visited[105][105];
int N, M;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

typedef struct {
    int r, c;
} Node;

Node queue[10000];

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        scanf("%d %d", &N, &M);

        int hr = -1, hc = -1;

        for (int i = 0; i < N; i++) {
            scanf("%s", map[i]);
            for (int j = 0; j < M; j++) {
                visited[i][j] = 0;
                if (map[i][j] == 'H') {
                    hr = i;
                    hc = j;
                }
            }
        }

        int front = 0, back = 0;

        // BFS from the cottage
        queue[back++] = (Node){hr, hc};
        visited[hr][hc] = 1;

        int danger = 0;

        while (front < back) {
            Node u = queue[front++];
            int r = u.r, c = u.c;

            for (int k = 0; k < 4; k++) {
                int nr = r + dx[k];
                int nc = c + dy[k];

                // bounds check
                if (nr < 0 || nr >= N || nc < 0 || nc >= M)
                    continue;

                // cannot walk into sea
                if (map[nr][nc] == 'S')
                    continue;

                if (!visited[nr][nc]) {
                    visited[nr][nc] = 1;

                    // If it's a komodo, count it
                    if (map[nr][nc] == 'K')
                        danger++;

                    queue[back++] = (Node){nr, nc};
                }
            }
        }

        printf("Case #%d: %d\n", tc, danger);
    }

    return 0;
}
