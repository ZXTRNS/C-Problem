#include <stdio.h>


int main(){
  long long a,b,hasil;

  scanf("%lld %lld", &a, &b);
  hasil = (b-a+1)*(a+b)/2;

  printf("%lld\n", hasil);

  return 0;
}