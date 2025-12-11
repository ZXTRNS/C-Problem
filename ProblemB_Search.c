#include <stdio.h>

long long sum_of_squares(int N) {
    return (long long) N * (N + 1) * (2 * N + 1) / 6;
}

int find_smallest_N(long long M) {
    // Binary search for the smallest N such that sum_of_squares(N) >= M
    long long left = 1, right = 1000000000;  // Set a large upper bound
    int best_N = -1;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long sum = sum_of_squares(mid);
        
        if (sum >= M) {
            best_N = mid;  // We found a valid N, but let's see if there's a smaller one
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return best_N;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        long long M;
        scanf("%lld", &M);

        int N = find_smallest_N(M);
        printf("Case #%d: %d\n", t, N);
    }

    return 0;
}
