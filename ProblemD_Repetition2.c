#include <stdio.h>
#include <string.h>

int main(){
  int t,i,j,longS[1001],c[1001]={0};
  char s[1001];
  
  scanf("%d", &t); 
  getchar();
  
  i=0;
  while(i<t){
    fgets(s, sizeof(s), stdin);
    longS[i] = strlen(s);
    if(s[longS[i]-1] == '\n'){
      s[longS[i]-1] ='\0';
      longS[i]--;
    }
    for(j=0; j<longS[i]/2; j++){
      c[i]+=(s[j]==s[longS[i]-1-j])? 1: 0;
      
    }
    i++;
  }
  i=0;
  while (i<t){
    (c[i] == longS[i]/2)? printf("Case #%d: Yay, it's a palindrome\n", i+1): printf("Case #%d: Nah, it's not a palindrome\n", i+1);
    i++;
  } 
  return 0;
}
