#include <stdio.h>

int binarySearch(int arr[], int n, int x) {
    int low = 0;
    int high = n-1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int N, M;
    int A[100005], Q[100005];
    int hasil = 0;
    
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    
    for (int i = 0; i < M; i++){
        scanf("%d", &Q[i]);
    }
    
    for (int i = 0; i < M; i++){
        hasil = binarySearch(A, N, Q[i]);
        if (hasil != -1)
        {
            // Tambahkan 1 pada hasil pencarian untuk indeks berbasis 1
            printf("%d\n", hasil + 1);
        }
        else
        {
            // Jika tidak ditemukan, cetak -1
            printf("%d\n", hasil);
        }
    }

    return 0;
}

