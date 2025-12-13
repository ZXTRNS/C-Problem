#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[105];
    int damage;
} Hero;

int ascending; // 1 = asc, 0 = dsc

int compare(const void *a, const void *b) {
    Hero *h1 = (Hero *)a;
    Hero *h2 = (Hero *)b;

    if (h1->damage == h2->damage) {
        return 0;
    }

    if (ascending) {
        return h1->damage - h2->damage;   // asc
    } else {
        return h2->damage - h1->damage;   // dsc
    }
}

int main() {
    int T;
    scanf("%d", &T);

    Hero heroes[T];

    for (int i = 0; i < T; i++) {
        scanf("%s %d", heroes[i].name, &heroes[i].damage);
    }

    char order[5];
    scanf("%s", order);

    ascending = (strcmp(order, "asc") == 0);

    qsort(heroes, T, sizeof(Hero), compare);

    for (int i = 0; i < T; i++) {
        printf("%s %d\n", heroes[i].name, heroes[i].damage);
    }

    return 0;
}
