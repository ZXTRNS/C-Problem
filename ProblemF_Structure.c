#include <stdio.h>

int main()
{
	int N, K, O[10001];
	float Temp, Hasil;

	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &O[i]);
	}

	for (int P = 0; P < K; P++) {
		O[P] = 0;
	}
	
	for (int J = N - 1; J >= N - K; J--){
		O[J] = 0;
	}
    
    Temp = 0;
	for (int Y = 0; Y < N; Y++){
	    Temp += O[Y];
	}
	
	N = N - (K * 2);
	Hasil = Temp/N;
	
	printf("%.2f\n", Hasil);

	return 0;
}