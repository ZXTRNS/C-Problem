#include <stdio.h>

int N;
int A[105];

void dfs(int idx, int sum) {
    if (idx > N) return;
    sum += A[idx];

    int left = 2*idx;
    int right = 2*idx + 1;

    if (left > N && right > N) {
        printf("%d\n", sum);
        return;
    }
    
    if (left <= N) dfs(left, sum);
    if (right <= N) dfs(right, sum);
}

int main() {
    int T;
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        scanf("%d", &N);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &A[i]);
        }

        printf("Case #%d:\n", tc);
        dfs(1, 0);
    }

    return 0;
}