#include <stdio.h>
#include <stdlib.h>

int *kudaJalan(int lokasi1[2], int lokasi2[2], int depth) {
  int i, posisiK1[2];
  int *step = (int *)malloc(8 * sizeof(int));
  int moves[8][2] = {
    {-2, +1}, {-2, -1}, {-1, +2}, {-1, -2},
    {+1, +2}, {+1, -2}, {+2, +1}, {+2, -1}
  };

  for (i = 0; i < 8; i++) {
    step[i] = 100;
  }

  if (lokasi1[0] == lokasi2[0] && lokasi1[1] == lokasi2[1]) {
    for (i = 0; i < 8; i++) {
      step[i] = 0;
    }
    return step;
  }

  if (depth > 6) {
    return step;
  }

  for (i = 0; i < 8; i++) {
    posisiK1[0] = lokasi1[0] + moves[i][0];
    posisiK1[1] = lokasi1[1] + moves[i][1];

    if (posisiK1[0] < 1 || posisiK1[0] > 8 || posisiK1[1] < 1 || posisiK1[1] > 8) {
      continue;
    }

    if (posisiK1[0] == lokasi2[0] && posisiK1[1] == lokasi2[1]) {
      step[i] = 1;
    } else {
      int *hasil = kudaJalan(posisiK1, lokasi2, depth + 1);
      int min = hasil[0];
      for (int j = 1; j < 8; j++) {
        if (hasil[j] < min) {
          min = hasil[j];
        }
      }
      step[i] = 1 + min;
      free(hasil);
    }
  }

  return step;
}

void coordinate(char a[3], int b[2]) {
  b[0] = a[0] - 'A' + 1;
  b[1] = a[1] - '0';
}

int main() {
  int i, j, t, temp, lokasiK1[2], lokasiK2[2];
  int *hasil;
  char lK1[3], lK2[3];

  scanf("%d", &t);

  for (i = 0; i < t; i++) {
    scanf("%s %s", lK1, lK2);
    coordinate(lK1, lokasiK1);
    coordinate(lK2, lokasiK2);

    hasil = kudaJalan(lokasiK1, lokasiK2, 0);

    temp = hasil[0];
    for (j = 1; j < 8; j++) {
      if (hasil[j] < temp) {
        temp = hasil[j];
      }
    }

    printf("Case #%d: %d\n", i + 1, temp);
    free(hasil);
  }

  return 0;
}
