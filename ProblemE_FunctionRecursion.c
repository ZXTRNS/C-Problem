#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int dx[8] = {2, 2, 1, 1, -1, -1, -2, -2};
int dy[8] = {1, -1, 2, -2, 2, -2, 1, -1};

bool visited[9][9][11];

bool canReach(int x, int y, int tx, int ty, int step) {
    if (x == tx && y == ty) return true;
    if (step == 0) return false;

    if (visited[x][y][step]) return false;
    visited[x][y][step] = true;

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8) {
            if (canReach(nx, ny, tx, ty, step - 1))
                return true;
        }
    }
    return false;
}

int main() {
    int T; 
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N;
        char bpos[3], wpos[3];
        scanf("%d", &N);
        scanf("%s %s", bpos, wpos);

        int bx = bpos[0] - 'A' + 1;
        int by = bpos[1] - '0';
        int wx = wpos[0] - 'A' + 1;
        int wy = wpos[1] - '0';

        bool meet = false;

        for (int i = 1; i <= 8 && !meet; i++) {
            for (int j = 1; j <= 8 && !meet; j++) {
                memset(visited, 0, sizeof(visited));
                bool b = canReach(bx, by, i, j, N);
                memset(visited, 0, sizeof(visited));
                bool w = canReach(wx, wy, i, j, N);
                if (b && w) meet = true;
            }
        }

        printf("Case #%d: %s\n", t, meet ? "YES" : "NO");
    }
    return 0;
}
