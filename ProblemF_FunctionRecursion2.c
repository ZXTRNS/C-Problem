#include <stdio.h>
int cekAngka(int a, int b){
  if(a!=b){
    if(a==1){
      return 0;
    } else if(a%2==0){
      return cekAngka(a / 2, b);
    } else{
      return cekAngka(a*3+1, b);
    }
  } else{
    return 1;
  }

}
int main(){
  int i,a,b,t;
  i=0;
  scanf("%d", &t);
  while(i<t){
    scanf("%d %d", &a,&b);
    printf("Case #%d: %s", i+1, (cekAngka(a,b))? "YES\n":"NO\n");
    i++;
  }

  return 0;
}