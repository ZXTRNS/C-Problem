#include<stdio.h>

int main(){
	
	int a,b,c,d;
	int e,f,g,h;
	int i,j,k,l;
	int m,n,o,p;
	
	scanf("%d %d %d %d", &a, &b, &c, &d); getchar();
	scanf("%d %d %d %d", &e, &f, &g, &h); getchar();
	scanf("%d %d %d %d", &i, &j, &k, &l); getchar();

	
	double hasil1 = (a + b + c)*2 + d;
	double hasil2 = (e + f + g)*2 + h;
	double hasil3 = (i + j + k)*2 + l;

	
	printf("%.2lf\n", hasil1);
	printf("%.2lf\n", hasil2);
	printf("%.2lf\n", hasil3);
	
	
return 0;
}