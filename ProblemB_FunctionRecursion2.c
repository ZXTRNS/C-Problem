#include <stdio.h>

int cekAir(char arr[101][101],int x, int y,int n, int m){
  int coorX[] = {1,0,-1,0};
  int coorY[] = {0,1,0,-1};
  int hasil = 0;
  int i;
  
  for(i=0;i<4;i++){
    int nx = x + coorX[i];
    int ny = y + coorY[i];
    if(nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == '.'){
      arr[nx][ny] = '#';
      hasil += 1 + cekAir(arr,nx,ny,n,m);
    }
  }
  return hasil;
}
int main(){
  int i,j,k,t,p,l,x,y,hasil[11];
  char input[101][101];
  i=0;
  scanf("%d", &t);
  while(i<t){
    scanf("%d %d", &p, &l);
    for(j=0;j<p;j++){
      for(k=0;k<l;k++){
        scanf(" %c", &input[j][k]);
        if(input[j][k]=='S'){
          x=j; y=k;
        }
      }
    }
    hasil[i] = cekAir(input, x,y,p,l);
    i++;
  }
  
  i=0;
  while(i<t){
    printf("Case #%d: %d\n", i+1, hasil[i]);
    i++;
  }
  return 0;
}