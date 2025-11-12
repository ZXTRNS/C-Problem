#include <stdio.h>
int fibo(int a, int b, int suku){
  if(suku==0){
    return a;
  } else if(suku==1){
    return b;
  } else{
    return fibo(a,b,suku-1)+ fibo(a,b,suku-2);
  }

}

int main(){
  int a,b,suku;
  scanf("%d %d", &a, &b);
  scanf("%d", &suku);
  int hasil = fibo(a,b,suku);
  printf("%d\n", hasil);
  return 0;
}