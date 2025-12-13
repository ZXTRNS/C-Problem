#include <stdio.h>
#include <stdlib.h>

long long A[30005], prefix[30005];

int cmp(const void *a, const void *b) {
    long long x = *(long long*)a;
    long long y = *(long long*)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

// lower_bound: first index where A[i] >= x
int lower_bound(long long arr[], int n, long long x) {
    int l = 0, r = n;
    while (l < r) {
        int m = (l + r) / 2;
        if (arr[m] >= x) r = m;
        else l = m + 1;
    }
    return l;
}

// upper_bound: first index where A[i] > x
int upper_bound(long long arr[], int n, long long x) {
    int l = 0, r = n;
    while (l < r) {
        int m = (l + r) / 2;
        if (arr[m] > x) r = m;
        else l = m + 1;
    }
    return l;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        int N;
        scanf("%d", &N);

        for (int i = 0; i < N; i++) {
            scanf("%lld", &A[i]);
        }

        // Sort array
        qsort(A, N, sizeof(long long), cmp);

        // Build prefix sum
        prefix[0] = A[0];
        for (int i = 1; i < N; i++) {
            prefix[i] = prefix[i - 1] + A[i];
        }

        int Q;
        scanf("%d", &Q);

        printf("Case #%d:\n", tc);

        while (Q--) {
            long long L, R;
            scanf("%lld %lld", &L, &R);

            int left = lower_bound(A, N, L);
            int right = upper_bound(A, N, R) - 1;

            if (left > right || left >= N || right < 0) {
                // No elements in range
                printf("0\n");
                continue;
            }

            long long sum = prefix[right];
            if (left > 0) sum -= prefix[left - 1];

            printf("%lld\n", sum);
        }
    }

    return 0;
}
