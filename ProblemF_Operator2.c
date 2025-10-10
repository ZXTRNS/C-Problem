#include<stdio.h>

long long a,b,c;

int main(){
	
	scanf("%lld %lld %lld", &a, &b, &c); getchar();
	
	long long hasil1 = a * b * c;
	
	printf("%lld\n", hasil1);
	
    return 0;
}