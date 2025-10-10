#include<stdio.h>

int main(){
	
	int a,b;
	
	scanf("%d %d", &a, &b); getchar();

	int hasil1 = a + b;
	int hasil2 = a - b;
	int hasil3 = a * b;
	int hasil4 = a / b;
	int hasil5 = a % b;

	
	printf("%d\n", hasil1);
	printf("%d\n", hasil2);
	printf("%d\n", hasil3);
	printf("%d\n", hasil4);
	printf("%d\n", hasil5);
	
    return 0;
}