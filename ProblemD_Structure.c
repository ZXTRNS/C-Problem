#include <stdio.h>
#include <stdlib.h>

int cmp_ll(const void *a, const void *b) {
    long long va = *(const long long*)a;
    long long vb = *(const long long*)b;
    if (va < vb) return -1;
    if (va > vb) return 1;
    return 0;
}

int main(void) {
    int N;
    if (scanf("%d", &N) != 1) return 0;
    if (N < 2) return 0; 

   
    long long *arr = (long long *) malloc((size_t)N * sizeof *arr);
    if (arr == NULL) return 0;

    for (int i = 0; i < N; i++) {
        if (scanf("%lld", &arr[i]) != 1) { free(arr); return 0; }
    }

    qsort(arr, (size_t)N, sizeof *arr, cmp_ll);

    long long maxDiff = -1; 
    for (int i = 1; i < N; i++) {
        long long diff = arr[i] - arr[i-1];
        if (diff > maxDiff) maxDiff = diff;
    }

    int firstPrinted = 1;
    for (int i = 1; i < N; i++) {
        if (arr[i] - arr[i-1] == maxDiff) {
            if (!firstPrinted) putchar(' ');
            printf("%lld %lld", arr[i-1], arr[i]);
            firstPrinted = 0;
        }
    }
    putchar('\n');

    free(arr);
    return 0;
}
