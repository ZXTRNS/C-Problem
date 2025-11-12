#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int height;
    int pos;
} Student;

int compare(const void *a, const void *b) {
    return ((Student*)a)->height - ((Student*)b)->height;
}

int binarySearch(Student arr[], int n, int target) {
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid].height == target)
            return arr[mid].pos;
        else if (arr[mid].height < target)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

int main() {
    int N;
    scanf("%d", &N);
    Student students[N];

    for (int i = 0; i < N; i++) {
        scanf("%d", &students[i].height);
    }

    qsort(students, N, sizeof(Student), compare);

    // assign sorted positions (1-based)
    for (int i = 0; i < N; i++) {
        students[i].pos = i + 1;
    }

    int Q;
    scanf("%d", &Q);

    for (int i = 0; i < Q; i++) {
        int x;
        scanf("%d", &x);
        int ans = binarySearch(students, N, x);
        printf("%d\n", ans);
    }

    return 0;
}
