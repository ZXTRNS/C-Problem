#include <stdio.h>

int main(){
  int i,j,k=0,n,cek[201]={0},temp[201], a=97;
  scanf("%d", &n);

  for(i=0;i<199;i++){
    for(j=1;j<198;j++){
      if((i+2)%j==0){
        cek[i]++;
      }
    }
  }
  for(i=0;i<199;i++){
    if(cek[i]==2){
      temp[k++] = i+2;
    }
  }
  i=0;
  while(i<n){
    if(i%26==0){
      a=97;
    }
    for(j=0;j<temp[i];j++){
      printf("%c", a);
    }
    printf("\n");
    a++;
    i++;
  }
  return 0;
}