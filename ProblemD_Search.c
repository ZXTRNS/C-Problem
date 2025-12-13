#include <stdio.h>

long long max_segment_length(int A[], int N, long long M) {
    int left = 0;
    long long current_sum = 0;
    int max_len = -1;

    for (int right = 0; right < N; ++right) {
        current_sum += A[right];

        // Shrink window
        while (current_sum > M && left <= right) {
            current_sum -= A[left];
            left++;
        }

        // Valid only if window is not empty
        if (left <= right && current_sum <= M) {
            int length = right - left + 1;
            if (length > max_len) max_len = length;
        }
    }

    return max_len;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N;
        long long M;
        scanf("%d %lld", &N, &M);

        int A[N];
        for (int i = 0; i < N; i++) scanf("%d", &A[i]);

        long long result = max_segment_length(A, N, M);
        printf("Case #%d: %lld\n", t, result);
    }

    return 0;
}