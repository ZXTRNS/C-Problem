#include<stdio.h>

char a,b;

int main(){
	
	scanf("%c %c", &a, &b); getchar();
	
	int c = (int)a;
	int d = (int)b;
	int hasil1 = c * d;
	
	printf("%d\n", hasil1);
	
    return 0;
}