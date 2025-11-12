#include <stdio.h>
#include <string.h>

char map[1001][1001];

int hitungRow(int row, int col, int N, char target) {
  if (col == N) return 0;
  return (map[row][col] == target) + hitungRow(row, col + 1, N, target);
}

int hitungCol(int row, int col, int N, char target) {
  if (row == N) return 0;
  return (map[row][col] == target) + hitungCol(row + 1, col, N, target);
}

int hitungDiag1(int i, int N, char target) {
  if (i == N) return 0;
  return (map[i][i] == target) + hitungDiag1(i + 1, N, target);
}

int hitungDiag2(int i, int N, char target) {
  if (i == N) return 0;
  return (map[i][N - 1 - i] == target) + hitungDiag2(i + 1, N, target);
}

int main() {
  int T, N;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%s", map[i]);
    int pSkor = 0, gSkor = 0;

    for (int i = 0; i < N; i++) {
      int c = hitungRow(i, 0, N, 'C');
      int p = hitungRow(i, 0, N, 'P');
      if (c > p) pSkor++;
      else if (p > c) gSkor++;
    }

    for (int j = 0; j < N; j++) {
      int c = hitungCol(0, j, N, 'C');
      int p = hitungCol(0, j, N, 'P');
      if (c > p) pSkor++;
      else if (p > c) gSkor++;
    }

    int c = hitungDiag1(0, N, 'C');
    int p = hitungDiag1(0, N, 'P');
    if (c > p) pSkor++;
    else if (p > c) gSkor++;

    c = hitungDiag2(0, N, 'C');
    p = hitungDiag2(0, N, 'P');
    if (c > p) pSkor++;
    else if (p > c) gSkor++;
    
    printf("Case #%d: ", t);
    if (pSkor > gSkor) printf("Pacman\n");
    else if (gSkor > pSkor) printf("Ghost\n");
    else printf("-\n");
  }
  return 0;
}