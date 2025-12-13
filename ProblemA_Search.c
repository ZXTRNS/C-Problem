#include <stdio.h>

int binarySearchFirst(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x) {
            ans = mid;
            high = mid - 1;  // keep searching to the left
        }
        else if (arr[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int N, M;
    int A[100005], Q[100005];

    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < M; i++) {
        scanf("%d", &Q[i]);
    }

    for (int i = 0; i < M; i++) {
        int pos = binarySearchFirst(A, N, Q[i]);
        if (pos == -1)
            printf("-1\n");
        else
            printf("%d\n", pos + 1);  // convert to 1-based index
    }

    return 0;
}
