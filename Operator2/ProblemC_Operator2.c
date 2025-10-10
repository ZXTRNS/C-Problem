#include<stdio.h>

int a,b,c,d,e,f;
char plus,equal;

int main(){
	
	scanf("%d %c %d %c", &a, &plus, &b, &equal); getchar();
	scanf("%d %c %d %c", &c, &plus, &d, &equal); getchar();
	scanf("%d %c %d %c", &e, &plus, &f, &equal); getchar();

	int hasil1 = a + b;
	int hasil2 = c + d;
	int hasil3 = e + f;
	
	printf("%d\n", hasil1);
	printf("%d\n", hasil2);
	printf("%d\n", hasil3);
	
    return 0;
}