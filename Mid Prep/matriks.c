#include <stdio.h>

int main(){
  int i,j,k,n,arr[101][101];
  scanf("%d", &n);
  int alomani = 1;
  
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      arr[i][j] = alomani++;
    }
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      printf("%d", arr[i][j]);
      if(j<n-1){
        printf(" ");
      } else{
        for(k=0;k<n;k++){
          printf(" -");
        }
        for(k=0;k<n;k++){
          printf(" %d", arr[i][n-k-1]);
        }
        printf("\n");
      }
    }
  }
  return 0;
}