#include<stdio.h>

int main(){
	
	float a,b;
	
	scanf("%f %f", &a, &b); getchar();

	float hasil1 = b/a * 100;
	
	printf("%.4f%%\n", hasil1);
	
    return 0;
}