#include<stdio.h>
#include<math.h>

double X,Y;
int n = 3;

int main(){
	
	scanf("%lf %lf", &X, &Y); getchar();
	
	double hasil1 = X * pow ((1 + (Y / 100)), n);
	
	printf("%.2lf\n", hasil1);
	
    return 0;
}