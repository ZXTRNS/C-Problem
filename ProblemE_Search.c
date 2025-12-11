#include <stdio.h>

long long sum_of_subarray(int A[], int left, int right) {
    long long sum = 0;
    for (int i = left; i <= right; ++i) {
        sum += A[i];
    }
    return sum;
}

int find_max_segment_length(int A[], int N, long long M) {
    int left = 0, right = 0;
    long long current_sum = 0;
    int max_length = -1;

    while (right < N) {
        // Expand the window by adding the current element
        current_sum += A[right];

        // Shrink the window if the sum exceeds M
        while (current_sum > M && left <= right) {
            current_sum -= A[left];
            left++;
        }

        // Check if the current sum is valid and update the max length
        if (current_sum <= M) {
            max_length = (right - left + 1) > max_length ? (right - left + 1) : max_length;
        }

        right++;
    }

    return max_length;
}

int main() {
    int N, Q;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    
    scanf("%d", &Q);
    for (int i = 1; i <= Q; i++) {
        long long M;
        scanf("%lld", &M);
        
        int result = find_max_segment_length(A, N, M);
        if (result == -1) {
            printf("Case #%d: -1\n", i);
        } else {
            printf("Case #%d: %d\n", i, result);
        }
    }

    return 0;
}
