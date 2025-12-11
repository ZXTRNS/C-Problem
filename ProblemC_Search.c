#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

// Function to find the largest index Y such that prefix_sum[Y] <= M using binary search
int binary_search(long long prefix_sum[], int N, long long M) {
    int left = 0, right = N - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (prefix_sum[mid] <= M) {
            result = mid; // this is a valid index, try to find a larger one
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    int N, Q;
    scanf("%d", &N);
    
    long long A[N], prefix_sum[N];
    
    // Reading the array A
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }
    
    // Calculate prefix sum array
    prefix_sum[0] = A[0];
    for (int i = 1; i < N; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + A[i];
    }

    scanf("%d", &Q);

    // Processing each query
    for (int t = 1; t <= Q; t++) {
        long long M;
        scanf("%lld", &M);

        int result = binary_search(prefix_sum, N, M);
        if (result == -1) {
            printf("Case #%d: -1\n", t);
        } else {
            printf("Case #%d: %d\n", t, result + 1); // Convert to 1-based index
        }
    }

    return 0;
}
