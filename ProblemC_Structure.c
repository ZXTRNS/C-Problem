#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Video {
    char title[1000];
    char artist[1000];
    int views;
};

int cmp(const void *a, const void *b) {
    struct Video *x = (struct Video*)a;
    struct Video *y = (struct Video*)b;
    
    if (x->views != y->views)
        return y->views - x->views; // besar ke kecil
    else
        return strcmp(x->title, y->title); // urut abjad
}

int main() {
    struct Video v[100];
    int n = 0;

    FILE *f = fopen("testdata.in", "r");
    while (fscanf(f, "%[^#]#%[^#]#%d\n", v[n].title, v[n].artist, &v[n].views) != EOF)
        n++;

    qsort(v, n, sizeof(struct Video), cmp);

    for (int i = 0; i < n; i++)
        printf("%s by %s - %d\n", v[i].title, v[i].artist, v[i].views);

    fclose(f);
    return 0;
}

