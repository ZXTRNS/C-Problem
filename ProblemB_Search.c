#include <stdio.h>
#include <limits.h>

long long sum_of_squares(long long N) {
    // Use __int128 to avoid overflow during multiplication
    __int128 n = (__int128) N;
    __int128 res = n * (n + 1) * (2 * n + 1) / 6;
    if (res > (__int128) LLONG_MAX) return LLONG_MAX;
    return (long long) res;
}

long long find_smallest_N(long long M) {
    // Find an upper bound safely by doubling (using safe arithmetic)
    long long left = 0, right = 1;
    while (sum_of_squares(right) < M) {
        right <<= 1; // double
        if (right > 5000000) { // safety cap to avoid infinite growth; 5e6 is more than enough
            right = 5000000;
            break;
        }
    }

    // Binary search for smallest N with sum_of_squares(N) >= M
    long long ans = -1;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long s = sum_of_squares(mid);
        if (s >= M) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    for (int t = 1; t <= T; t++) {
        long long M;
        scanf("%lld", &M);
        long long N = find_smallest_N(M);
        printf("Case #%d: %lld\n", t, N);
    }
    return 0;
}