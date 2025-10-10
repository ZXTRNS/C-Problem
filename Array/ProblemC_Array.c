#include <stdio.h>
#include <stdlib.h>

// comparison function for qsort
int cmp(const void *a, const void *b) {
    long long x = *(long long *)a;
    long long y = *(long long *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int N;
    scanf("%d", &N);

    long long arr[N];
    for (int i = 0; i < N; i++)
        scanf("%lld", &arr[i]);

    // sort the array
    qsort(arr, N, sizeof(long long), cmp);

    int count = 1; // at least one unique number
    for (int i = 1; i < N; i++) {
        if (arr[i] != arr[i - 1])
            count++;
    }

    printf("%d\n", count);
    return 0;
}