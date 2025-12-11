#include <stdio.h>

long long max_segment_length(int A[], int N, long long M) {
    int left = 0;
    long long current_sum = 0;
    int max_len = -1;

    // Use the sliding window technique
    for (int right = 0; right < N; ++right) {
        // Expand the window by including A[right]
        current_sum += A[right];

        // Shrink the window if the sum exceeds M
        while (current_sum > M && left <= right) {
            current_sum -= A[left];
            left++;
        }

        // Update the maximum length of valid subarray
        if (current_sum <= M) {
            max_len = (right - left + 1) > max_len ? (right - left + 1) : max_len;
        }
    }

    return max_len;
}

int main() {
    int T;  // Number of test cases
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {
        int N;
        long long M;
        scanf("%d %lld", &N, &M);

        int A[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }

        long long result = max_segment_length(A, N, M);
        if (result == -1) {
            printf("Case #%d: -1\n", t);
        } else {
            printf("Case #%d: %lld\n", t, result);
        }
    }

    return 0;
}
