#include <stdio.h>
long long fibo(long long a, long long b, int suku){
  if(suku==0){
    return a;
  } else if(suku==1){
    return b;
  } else{
    return fibo(a,b,suku-1) - fibo(a,b,suku-2);
  }
}

int main(){
  int i,t,suku;
  long long a,b,hasil;
  i=0;
  scanf("%d", &t);

  while(i<t){
    scanf("%d %lld %lld", &suku,&a,&b);
    hasil = fibo(a,b,suku);
    printf("Case #%d: %lld\n", i+1,hasil);
    i++;
  }
  return 0;
}