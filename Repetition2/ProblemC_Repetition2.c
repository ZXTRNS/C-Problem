#include <stdio.h>

int main(){
  int t,i,a,b,hasil[10];
  
  scanf("%d", &t);
  
  
  
  for(i=0; i<t; i++){
    scanf("%d %d", &a,&b);
    hasil[i] = ((a/b)<<b);
  }
  
  for(i=0; i<t; i++){
    printf("%d\n", hasil[i]);
  }
  
  return 0;
}
