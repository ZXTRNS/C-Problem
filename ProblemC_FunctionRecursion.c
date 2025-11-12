#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

char map[MAX_SIZE][MAX_SIZE];
int N, M;
int food_count;

void dfs(int r, int c) {

    if (r < 0 || r >= N || c < 0 || c >= M) {
        return;
    }

    if (map[r][c] == '#' || map[r][c] == 'V') {
        return;
    }

    if (map[r][c] == '*') {
        food_count++;
    }

    map[r][c] = 'V'; 

    dfs(r + 1, c); // bawah
    dfs(r - 1, c); // atas
    dfs(r, c + 1); // kanan
    dfs(r, c - 1); // kiri
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int start_r = -1, start_c = -1;
        food_count = 0;
        
        scanf("%d %d", &N, &M);

        for (int i = 0; i < N; i++) {
            scanf("%s", map[i]);
            
            for (int j = 0; j < M; j++) {
                if (map[i][j] == 'P') {
                    start_r = i;
                    start_c = j;
                }
            }
        }
        
        if (start_r != -1) {
            dfs(start_r, start_c);
        }
        printf("Case #%d: %d\n", t, food_count);
    }

    return 0;
}
