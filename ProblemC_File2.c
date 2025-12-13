#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int mmr;
} Player;

int compare(const void *a, const void *b) {
    Player *p1 = (Player *)a;
    Player *p2 = (Player *)b;

    if (p1->mmr != p2->mmr) {
        return p2->mmr - p1->mmr;
    }

    return strcmp(p1->name, p2->name);
}

int main() {
    int N;
    scanf("%d", &N);

    Player players[N];

    for (int i = 0; i < N; i++) {
        scanf("%s %d", players[i].name, &players[i].mmr);
    }

    qsort(players, N, sizeof(Player), compare);

    for (int i = 0; i < N; i++) {
        printf("%s %d\n", players[i].name, players[i].mmr);
    }

    return 0;
}
