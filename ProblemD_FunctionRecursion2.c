#include <stdio.h>
int jobonaci(int s){
  if(s==0 || s==1 || s==2 || s==3){
    return 1;
  } else if(s%2==1){
    return 1;
  } else{
    return jobonaci(s-1) + jobonaci(s-2);
  }
}
int main(){
  int s;
  scanf("%d", &s);
  printf("%d\n", jobonaci(s));

  return 0;
}