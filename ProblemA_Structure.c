#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int R;
    char *name;
} Plant;

static void trim_trailing_newline(char *s) {
    size_t n = strlen(s);
    if (n == 0) return;
    if (s[n-1] == '\n') s[n-1] = '\0';
    if (n >= 2 && s[n-2] == '\r') s[n-2] = '\0'; // handle CRLF
}

static char *ltrim(char *s) {
    while (*s && isspace((unsigned char)*s)) s++;
    return s;
}

static int ci_compare_str(const char *a, const char *b) {
    // case-insensitive lexicographical compare
    while (*a && *b) {
        char ca = tolower((unsigned char)*a);
        char cb = tolower((unsigned char)*b);
        if (ca < cb) return -1;
        if (ca > cb) return 1;
        a++; b++;
    }
    if (*a) return 1;
    if (*b) return -1;
    return 0;
}

int cmp_plants(const void *pa, const void *pb) {
    const Plant *A = pa;
    const Plant *B = pb;
    return ci_compare_str(A->name, B->name);
}

int main(void) {
    FILE *f = fopen("testdata.in", "r");
    if (!f) {
        f = stdin; // fallback to stdin if file not present
    }

    char line[4096];
    if (!fgets(line, sizeof(line), f)) return 0;
    trim_trailing_newline(line);
    char *p = ltrim(line);
    if (*p == '\0') {
        // skip blank lines until we find N or EOF
        while (fgets(line, sizeof(line), f)) {
            trim_trailing_newline(line);
            p = ltrim(line);
            if (*p != '\0') break;
        }
    }
    if (!p || *p == '\0') return 0;

    int N = atoi(p);
    if (N <= 0) return 0;

    Plant *arr = malloc(sizeof(Plant) * N);
    if (!arr) return 0;

    int readCount = 0;
    while (readCount < N && fgets(line, sizeof(line), f)) {
        trim_trailing_newline(line);
        char *s = ltrim(line);
        if (*s == '\0') continue; // skip empty line

        // find first '#'
        char *hash = strchr(s, '#');
        if (!hash) {
            // malformed line — skip
            continue;
        }

        *hash = '\0';
        char *rpart = ltrim(s);
        char *mpart = ltrim(hash + 1);

        // parse R
        int R = atoi(rpart);

        // trim trailing spaces in mpart
        size_t mlen = strlen(mpart);
        while (mlen > 0 && isspace((unsigned char)mpart[mlen-1])) {
            mpart[mlen-1] = '\0';
            mlen--;
        }

        // allocate and store
        arr[readCount].R = R;
        arr[readCount].name = malloc(mlen + 1);
        if (!arr[readCount].name) {
            // cleanup and exit
            for (int k = 0; k < readCount; k++) free(arr[k].name);
            free(arr);
            return 0;
        }
        strcpy(arr[readCount].name, mpart);

        readCount++;
    }

    // if file was opened, close it (but don't close stdin)
    if (f != stdin) fclose(f);

    // sort by name (case-insensitive)
    qsort(arr, readCount, sizeof(Plant), cmp_plants);

    // print output in format "R M"
    for (int i = 0; i < readCount; i++) {
        printf("%d %s\n", arr[i].R, arr[i].name);
        free(arr[i].name);
    }

    free(arr);
    return 0;
}