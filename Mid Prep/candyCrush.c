#include <stdio.h>
#include <string.h>

int main(){
  int i,j,n;
  char input[101],temp[101];
  scanf("%s", input);
  n = strlen(input);
  for(i=0;i<n;i++){
      for(j=1+i;j<n;j++){
          if(input[i]-input[j]==32 || input[i]-input[j]==-32){
              input[i] = ' ';
              input[j] = ' ';
              break;
          }
      }
  }
  j=0;
  for(i=0;i<n;i++){
      if(input[i]!=' '){
          temp[j++] = input[i];
      }
  }
  int m = strlen(temp);
  for(i=0;i<m;i++){
      printf("%c ", temp[i]);
  }

  return 0;
}